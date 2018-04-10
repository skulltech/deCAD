#ifndef ALGORITHMS_H
#define ALGORITHMS_H



using namespace std;


class Vertex {
	public:
	tuple <float,float,float> v;
	Vertex(float a, float b, float c);
	friend ostream& operator<<(ostream& os, const Vertex& vertex);
};

class Point {
	public:
	tuple <float,float> p;
	Point();
	Point(float a, float b);
	void print();
	friend ostream& operator<<(ostream& os, const Point& point);
};

class Plane {
	public:
	float a, b, c, d;
	Plane(float a1, float b1, float c1, float d1);
	void print();
	float squareNormal();
	friend ostream& operator<<(ostream& os, const Plane& plane);
};

class Projection {
	public:
	vector<Point> points;
	vector<tuple<int, int>> edges;
	Projection();
	Projection (vector<Point> p, vector<tuple<int, int>> e);
	void print();
	friend ostream& operator<<(ostream& os, const Projection& proj);
};

class Model {
	public:
	vector<Vertex> vertices;
	vector<tuple<int, int>> edges;
	Model(vector<Vertex> v, vector<tuple<int, int>> e);
	friend ostream& operator<<(ostream& os, const Model& model);
};

Point isometricProjPoint(Vertex v);

Projection isometricProjection(Model m);

Projection flatModelToProjection(Model m);

Projection modelToProjection(Model m, Plane p);

Model projectionsToModel(Projection p1, Projection p2, Projection p3);

bool checkEdge(vector<tuple<int,int>> edges, tuple<int,int> e);

tuple<float, float, float> crossProduct(tuple<float, float, float> a, tuple<float, float, float> b);

float dotProduct(tuple<float, float, float> a, tuple<float, float, float> b);

#endif