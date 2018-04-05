#ifndef IO_H
#define IO_H

using namespace std;

tuple<Model, Plane> read3DInputFile(string filename);
vector<Projection> read2DInputFile(string filename);
int drawProjection(Projection proj, int argc, char *argv[]);

#endif