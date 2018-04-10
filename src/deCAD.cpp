#include <iostream>
#include <fstream>
#include <tuple>
#include <string>
#include <vector>
#include <QtCore>
#include <QtWidgets>
#include "algorithms.h"
#include "io.h"
#include "args.hxx"

using namespace std;


void output(string message, bool verbose) {
  if (verbose) {
    cout <<  message << endl;
  }
}


int main(int argc, char *argv[]) {
  args::ArgumentParser parser("deCAD. Best CAD tool ever!", "Authors are Sumit Ghosh and Ankit Solanki.");
  args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
  args::Flag verbose(parser, "verbose", "Verbose mode", {'v', "verbose"});
  args::Positional<string> inputType(parser, "inputType", "Type of input [2D, 3D]");
  args::Positional<string> inputFile(parser, "inputFile", "Input File");
  
  try {
      parser.ParseCLI(argc, argv);
  } catch (args::Help) {
      cout << parser;
      return 0;
  } catch (args::ParseError e) {
      cerr << e.what() << endl;
      cerr << parser;
      return 1;
  }

  string inputTypeString(args::get(inputType));
  string inputFileString(args::get(inputFile));

  if (inputTypeString=="" || inputFileString=="") {
    cout << "    Some required CLI options are not provided!\n    Run ./deCAD -h for usage instructions.\n"<< endl;
    exit(1);
  }



  if (inputTypeString=="3D") {
    if (verbose) { cout << "[*] Reading 3D input from " << inputFileString << endl << endl; }
    tuple<Model, Plane> input3D = read3DInputFile(inputFileString);
    if (verbose) { cout << get<0>(input3D) << endl << get<1>(input3D) << endl; }
    Projection proj = modelToProjection(get<0>(input3D), get<1>(input3D));
    if (verbose) { cout << proj << endl; }
    int ret = drawProjection(proj, argc, argv);
    return ret;
  
  } else if (inputTypeString=="2D") {
    if (verbose) { cout << "[*] Reading 2D input from " << inputFileString << endl; }
    vector<Projection> projs = read2DInputFile(inputFileString);

    if (verbose) {
      cout << endl << "The input projections are: " << endl << endl;
      for (Projection proj: projs) {
        cout << proj << endl;
      }
    }

    Model modl = projectionsToModel(projs.at(0), projs.at(1), projs.at(2));
    
    if (verbose) { cout << modl << endl; }
    Projection proj = isometricProjection(modl);
    if (verbose) { cout << proj << endl; }
    
    int ret = drawProjection(proj, argc, argv);
    return ret;
  }

  else {
    cout << "[*] Invalid inputType parameter given!"<< endl;
    return 1;
  }
}
