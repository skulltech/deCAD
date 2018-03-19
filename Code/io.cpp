#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

using namespace std;



class vertex {
	public:
	tuple <float,float,float> v;

	vertex(float a, float b, float c) {
		v = make_tuple(a,b,c);
	}
	
	void print_vertex() {
		cout << (get<0>(v)) << ", " << (get<1>(v)) << ", " <<(get<2>(v)) << endl;
	}
};


class point {
	public:
	tuple <float,float> p;

	point(float a, float b) {
		p = make_tuple(a, b);
	}
	
	void print_vertex() {
		cout << (get<0>(p)) << ", " << (get<1>(p)) << endl;
	}
};


class plane {
	public:
	float a,b,c,d; // The equation of plane is ax+by+cz+d=0;
	tuple <float,float,float> normal;

	plane(float a1,float b1, float c1, float d1){
		a = a1; b = b1; c = c1; d = d1;
		normal = make_tuple(a1,b1,c1);
	}

	void print_normal() {
		cout<< (get<0>(normal)) << "i^ + " << get<1>(normal)<< "j^ +" << get<2>(normal) << "k^ " << endl;
	}

	float square_normal(){
		return (a*a + b*b + c*c); 
	}
};

class projection {
public:
	vector<point> vertices;
	vector<tuple<int, int>> edges;
};

class model {
public:
	vector<vertex> vertices;
	vector<tuple<int, int>> edges;

	model(vector<vertex> v, vector<tuple<int, int>> e) {
		vertices = v;
		edges = e;
	}
};

class algorithms {
	public:
	/**
	* Algorithm implementation for converting given 3D model 
	* into a 2D projection on the given plane.
	*/
	model model_to_projections(model m, plane p) {
		vector<vertex> v1;

		for(vertex v: m.vertices) {
			float temp1=(get<0>(p.normal)*(get<0>(v.v))+(get<1>(p.normal)*(get<1>(v.v)))+(get<2>(p.normal))*(get<2>(v.v)));
			float temp2=(p.square_normal());

			vertex projw((temp1/temp2)*(get<0>(p.normal)),(temp1/temp2)*(get<1>(p.normal)),(temp1/temp2)*(get<2>(p.normal)));

			v1.push_back(vertex((get<0>(v.v)-get<0>(projw.v)),(get<1>(v.v)-get<1>(projw.v)),(get<2>(v.v)-get<2>(projw.v))));
		}

		return model(v1, m.edges);
	}

};

int main(){
	float d1,d2,d3,d4;
	int e1,e2;
	int num;

	ifstream infile;
	infile.open("input.txt");

	// take vertex inputs
	infile >> num;
	
	vector<vertex> vertices;

 	for(int i=0;i<(num);i++){
		infile>>d1>>d2>>d3>>d4;
		vertices.push_back(vertex(d2,d3,d4));
	}

	// take edges input
	infile >> num;
	
	vector<tuple<int,int>> edges;

 	for(int i=0;i<(num);i++){
		infile>>e1>>e2;
		edges.push_back(make_tuple(e1,e2));
	}

	// take plane input
	infile>>d1>>d2>>d3>>d4;
	plane pl(d1,d2,d3,d4);

	infile.close();

	model m1(vertices,edges);

	algorithms a1;

	model m2 = a1.model_to_projections(m1, pl);

	for (vertex i: m2.vertices){
		cout<<(get<0>(i.v))<<" "<<(get<1>(i.v))<<" "<<(get<2>(i.v))<<endl;
	}

}