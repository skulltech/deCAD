#include <iostream>
#include <fstream>
#include <tuple>
#include <string>
#include <vector>
#include <QtCore>
#include <QtWidgets>
#include "algorithms.h"
#include "io.h"

using namespace std;


int main(int argc, char *argv[])
{
  tuple<Model, Plane> input3D = read3DInputFile("3Dinput.txt");
  Projection proj = modelToProjection(get<0>(input3D), get<1>(input3D));
  cout << proj.points.size() << endl;
  proj.points.at(0).print();
  proj.points.at(1).print();
  cout << proj.edges.size() << endl;
  int ret = drawProjection(proj, argc, argv);


  // cout << "Starting" << endl;
  // vector<Projection> projs = read2DInputFile("2Dinput.txt");
  // cout << "Calling" << endl;

  // Model modl = projectionsToModel(projs.at(0), projs.at(1), projs.at(2));
  // cout << "Calling" << endl;
  // Projection proj = isometricProjection(modl);
  // cout << "done" << endl;
  // int ret = drawProjection(proj, argc, argv);
  // cout << "fcu" << endl;

  return ret;
}
