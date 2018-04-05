#include <iostream>
#include <math.h>
#include <tuple>
#include <vector>
#include <string>
#include "algorithms.h"

using namespace std;



Vertex::Vertex(float a, float b, float c) {
		v = make_tuple(a,b,c);
}
	
void Vertex::print() { cout << "Vertex ["<< (get<0>(v))<< ", "<< (get<1>(v))<< ", "<<(get<2>(v))<< "]"<< endl; }


Point::Point(){}
Point::Point(float a, float b) { p = make_tuple(a, b); }
	
void Point::print() {
	cout << "Point ["<< (get<0>(p))<< ", "<< (get<1>(p))<< "]"<< endl;
}



Plane::Plane(float a1, float b1, float c1, float d1) {
	a = a1; b = b1; c = c1; d = d1;
}

void Plane::print() {
	cout<< "Plane ["<< a<< "x + "<< b<< "y + "<< c<< "z + "<< d<< " = 0]"<< endl;
}

float Plane::squareNormal() {
	return (a*a + b*b + c*c); 
}


Projection::Projection() { }

Projection::Projection (vector<Point> p, vector<tuple<int, int>> e) {
	points = p;
	edges = e;
}


Model::Model(vector<Vertex> v, vector<tuple<int, int>> e) {
	vertices = v;
	edges = e;
}



Point isometricProjPoint(Vertex v) {
	cout << "star";

	float aMatrix[3][3] = {{sqrt(3), 0, -sqrt(3)}, {1, 2, 1}, {sqrt(2), -sqrt(2), sqrt(2)}};
	float bMatrix[3][1] = {{get<0>(v.v)}, {get<1>(v.v)}, {get<2>(v.v)}};
	float product[3][1] = {{0}, {0}, {0}};  

	for (int row = 0; row < 3; row++) {  
	   for (int col = 0; col < 1; col++) {  
	       // Multiply the row of A by the column of B to get the row, column of product.  
	       for (int inner = 0; inner < 3; inner++) {  
	           product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];  
	       }  
	   }
	}

	cout << "Dasd";

	return Point(product[0][0], product[1][0]);
}


Projection isometricProjection(Model m) {
	cout << 1;
	Projection proj;
	cout << 2;

	for (Vertex v: m.vertices) {
		cout << 3;
		proj.points.push_back(isometricProjPoint(v));
	}
	proj.edges = m.edges;
	cout << 4;

	return proj;
}


Projection flatModelToProjection(Model m) {
	// To write!!
}


/*!
Algorithm implementation for converting given 3D model 
into a 2D projection on the given plane.
*/
Projection modelToProjection(Model m, Plane p) {
	vector<Vertex> vertices;

	for(Vertex v: m.vertices) {
		float temp1 = (p.a*(get<0>(v.v))) + (p.b*(get<1>(v.v))) + (p.c*(get<2>(v.v)));
		float temp2 = p.squareNormal();
		Vertex projw((temp1/temp2)*p.a, (temp1/temp2)*p.b, (temp1/temp2)*p.c);
		Vertex v1((get<0>(v.v)-get<0>(projw.v)), (get<1>(v.v)-get<1>(projw.v)), (get<2>(v.v)-get<2>(projw.v)));
		
		vertices.push_back(v1);
	}

	return flatModelToProjection(Model(vertices, m.edges));
}

/*
Algorithm implementation for converting given 2D projections
into a 2D model.
*/
Model projectionsToModel(Projection p1, Projection p2, Projection p3) {
	vector<Point> v1, v2, v3;

	Point first = p1.points.at(0);
	int x1 = get<0>(first.p);
	int y1 = get<1>(first.p);
	for (Point v: p1.points) {
		v1.push_back(Point(get<0>(v.p) - x1, get<1>(v.p) - y1));
	}

	Point second = p2.points.at(0);
	x1 = get<0>(second.p);
	y1 = get<1>(second.p);
	for (Point v: p2.points) {
		v2.push_back(Point(get<0>(v.p) - x1, get<1>(v.p) - y1));
	}

	Point third = p3.points.at(0);
	x1 = get<0>(third.p);
	y1 = get<1>(third.p);
	for (Point v: p3.points) {
		v3.push_back(Point(get<0>(v.p) - x1, get<1>(v.p) - y1));
	}

	vector<Vertex> vertices;

	for (int i=0; i<p1.points.size(); i++) {
		vertices.push_back(Vertex(get<0>(v1.at(i).p), get<0>(v2.at(i).p), get<0>(v3.at(i).p)));
	}

	vector<tuple<int, int>> edges;
	for (int e=0; e < p1.edges.size();e++) {
		if (checkEdge(p2.edges ,p1.edges.at(e))) {
		    if (checkEdge(p3.edges, p1.edges.at(e))) {
		    	edges.push_back(p1.edges.at(e));
		    }
		}
	}

	return Model(vertices, edges);;
}


bool checkEdge(vector<tuple<int,int>> edges, tuple<int,int> e) {
	for (int j=0; j<edges.size(); j++) {
		if (get<0>(edges.at(j))==get<0>(e) && get<1>(edges.at(j))==get<1>(e)) {
			return true;
		}
	}
	return false;
}
