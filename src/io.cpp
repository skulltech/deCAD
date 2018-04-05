#include <math.h>
#include <fstream>
#include <QtCore>
#include <string>
#include <iostream>
#include <QtWidgets>
#include "algorithms.h"
#include "io.h"


#define FACTOR 100.0
using namespace std;
using namespace Qt;



tuple<Model, Plane> read3DInputFile(string filename) {
   float d1,d2,d3,d4;
   int e1,e2;
   int num;

   ifstream infile;
   infile.open(filename);

   // take vertex inputs
   infile >> num;
   vector<Vertex> vertices;
   for(int i=0; i<(num); i++) {
      infile >> d1 >> d2 >> d3 >> d4;
      vertices.push_back(Vertex(d2, d3, d4));
   }

   // take edges input
   infile >> num;
   vector<tuple<int, int>> edges;
   for(int i=0; i<(num); i++){
      infile >> e1>> e2;
      edges.push_back(make_tuple(e1, e2));
   }

   // take plane input
   infile >> d1 >> d2 >> d3 >> d4;
   infile.close();

   Plane p(d1, d2, d3, d4);
   Model m(vertices, edges);

   return make_tuple(m, p);
}


vector<Projection> read2DInputFile(string filename) {
   float d1, d2, d3, d4;
   int e1, e2;
   int num;

   vector<Projection> projs;
   ifstream infile;
   infile.open(filename);

   for (int i=0; i<3; i++) {
      infile >> num;
      vector<Point> points;
      for(int i=0; i<(num); i++) {
         infile >> d1 >> d2;
         points.push_back(Point(d1, d2));
      }

      infile >> num;
      vector<tuple<int,int>> edges;
      for(int i=0; i<(num); i++) {
         infile >> e1 >> e2;
         edges.push_back(make_tuple(e1,e2));
      }

      Projection proj(points, edges);
      projs.push_back(proj);
   }

   infile.close();
   return projs;
}


void drawProjection(Projection proj) {
   QLabel l;
   QPicture pi;
   QPainter p(&pi);

   p.setRenderHint(QPainter::Antialiasing);
   p.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));

   for (tuple<int, int> edge: proj.edges) {
      Point u = proj.points.at(get<0>(edge));
      Point v = proj.points.at(get<1>(edge));
      p.drawLine(FACTOR*(get<0>(u.p)), FACTOR*(get<1>(u.p)), FACTOR*(get<0>(v.p)), FACTOR*(get<1>(v.p)));
   }
   p.end();

   l.setPicture(pi);
   l.show();
}
