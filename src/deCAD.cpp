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
  cout << "asdasd";
  QApplication a(argc, argv);

  // tuple<Model, Plane> input3D = read3DInputFile("3Dinput.txt");
  // Projection proj = modelToProjection(get<0>(input3D), get<1>(input3D));
  // drawProjection(proj);
  cout << "Starting";
  vector<Projection> projs = read2DInputFile("2Dinput.txt");
  cout << "Calling";

  Model modl = projectionsToModel(projs.at(0), projs.at(1), projs.at(2));
  cout << "Calling";
  Projection proj = isometricProjection(modl);
  cout << "done";
  drawProjection(proj);
  cout << "fcu";

  return a.exec();
  cout << "dam";
}
