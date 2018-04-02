#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithms.h>

using namespace std;


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  3Dinput = read3DInputFile("3Dinput.txt");
  Projection proj = modelToProjection(get<0>3Dinput, get<1>3Dinput);
  drawProjection(proj);

  vector<Projection> projs = read2DInputFile("2Dinput.txt");
  Model modl = projectionsToModel(get<0>projs, get<1>projs, get<2>projs);
  Projection proj = isometricProjection(modl);
  drawProjection(proj);

  return a.exec();
}
