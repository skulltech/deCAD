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
	
ostream& operator<<(ostream& os, const Vertex& vertex) {
	os << "Vertex ["<< (get<0>(vertex.v))<< ", "<< (get<1>(vertex.v))<< ", "<< (get<2>(vertex.v))<< "]";
	return os;
}

Point::Point(){}
Point::Point(float a, float b) { p = make_tuple(a, b); }
	
ostream& operator<<(ostream& os, const Point& point) {
	os << "Point ["<< (get<0>(point.p))<< ", "<< (get<1>(point.p))<< "]";
	return os;
}

Plane::Plane(float a1, float b1, float c1, float d1) {
	a = a1; b = b1; c = c1; d = d1;
}

ostream& operator<<(ostream& os, const Plane& plane) {
	os << "Plane ["<< plane.a<< "x + "<< plane.b<< "y + "<< plane.c<< "z + "<< plane.d<< " = 0]";
	return os;
}

float Plane::squareNormal() {
	return (a*a + b*b + c*c); 
}

Projection::Projection() { }

Projection::Projection (vector<Point> p, vector<tuple<int, int>> e) {
	points = p;
	edges = e;
}

ostream& operator<<(ostream& os, const Projection& proj) {
	os << "Projection with " << proj.points.size() << " points and " << proj.edges.size() << " edges" << endl;
	os << "The Points are:" << endl;
	for (Point p: proj.points) {
		os << p << endl;
	}	
	return os;
}

Model::Model(vector<Vertex> v, vector<tuple<int, int>> e) {
	vertices = v;
	edges = e;
}

ostream& operator<<(ostream& os, const Model& model) {
	os << "Model with " << model.vertices.size() << " vertices and " << model.edges.size() << " edges" << endl;
	os << "The Vertices are:" << endl;
	for (Vertex v: model.vertices) {
		os << v << endl;
	}	
	return os;
}

Point isometricProjPoint(Vertex v) {
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

	return Point(product[0][0], product[1][0]);
}


Projection isometricProjection(Model m) {
	Projection proj;

	for (Vertex v: m.vertices) {
		proj.points.push_back(isometricProjPoint(v));
	}
	proj.edges = m.edges;

	return proj;
}


Projection flatModelToProjection(Model m, Plane p) {
	int rand1 = rand() % (10 - 2 + 1) + 2;
	int rand2 = rand() % (10 - 2 + 1) + 2;
	int rand3 = rand() % (10 - 2 + 1) + 2;


	tuple<float, float, float> normal = make_tuple(p.a, p.b, p.c);
	tuple<float, float, float> n0 = make_tuple(p.a+rand1, p.b+rand2, p.c+rand3);

	tuple<float, float, float> e1 = crossProduct(normal, n0);
	tuple<float, float, float> e2 = crossProduct(normal, e1);

	float deno1 = sqrt(get<0>(e1)*get<0>(e1)+get<1>(e1)*get<1>(e1)+get<2>(e1)*get<2>(e1));
	float deno2 = sqrt(get<0>(e2)*get<0>(e2)+get<1>(e2)*get<1>(e2)+get<2>(e2)*get<2>(e2));

	tuple<float, float, float> _e1 = make_tuple(get<0>(e1)/deno1, get<1>(e1)/deno1, get<2>(e1)/deno1);
	tuple<float, float, float> _e2 = make_tuple(get<0>(e2)/deno2, get<1>(e2)/deno2, get<2>(e2)/deno2);

	Projection proj;

	for (Vertex v: m.vertices) {
		proj.points.push_back(Point(dotProduct(_e1, v.v), dotProduct(_e2, v.v)));
	}
	proj.edges = m.edges;

	return proj;
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

	return flatModelToProjection(Model(vertices, m.edges), p);
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
		vertices.push_back(Vertex(get<0>(v1.at(i).p), get<1>(v2.at(i).p), get<0>(v3.at(i).p)));
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

tuple<float, float, float> crossProduct(tuple<float, float, float> a, tuple<float, float, float> b) {
	return make_tuple(  ((get<1>(a)*get<2>(b)) - (get<1>(b)*get<2>(a))), 
						((get<2>(a)*get<0>(b)) - (get<0>(a)*get<2>(b))), 
						((get<0>(a)*get<1>(b)) - (get<1>(a)*get<0>(b)))
					 );
}

float dotProduct(tuple<float, float, float> a, tuple<float, float, float> b) {
	return (get<0>(a)*get<0>(b)) + (get<1>(a)*get<1>(b)) + (get<2>(a)*get<2>(b));
}