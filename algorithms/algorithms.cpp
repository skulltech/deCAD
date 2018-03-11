#include <iostream>
#include <set>
#include <tuple>

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
}

class model {
public:
	vector<vertex> vertices;
	vector<tuple<int, int>> edges;

	model(vector<vertex> v, vector<tuple<int, int>> e) {
		vertices = v;
		edges = e;
	}
}

class algorithms {
	public:
	/**
	* Algorithm implementation for converting given 3D model 
	* into a 2D projection on the given plane.
	*/
	vertex model_to_projections(vertex v, plane p) {

		float temp1=(get<0>(p.normal)*(get<0>(v.v))+(get<1>(p.normal)*(get<1>(v.v)))+(get<2>(p.normal))*(get<2>(v.v)));
		float temp2=(p.square_normal());

		vertex projw((temp1/temp2)*(get<0>(p.normal)),(temp1/temp2)*(get<1>(p.normal)),(temp1/temp2)*(get<2>(p.normal)));
		vertex q((get<0>(v.v)-get<0>(projw.v)),(get<1>(v.v)-get<1>(projw.v)),(get<2>(v.v)-get<2>(projw.v)));

		return q;
	}

	/**
	* Algorithm implementation for converting given 2D projections
	* into a 2D model.
	*/
	model projections_to_model(projection p1, projection p2, projection p3) {
		vector<point> v1, v2, v3;

		point first = p1.vertices.at(0);
		int x1 = get<0>first;
		int y1 = get<1>first;
		for (vertex v: p1.vertices) {
			v1.push_back(make_tuple(get<0>v - x1, get<1>v - y1))
		}

		point first = p2.vertices.at(0);
		int x1 = get<0>first;
		int y1 = get<1>first;
		for (vertex v: p2.vertices) {
			v1.push_back(make_tuple(get<0>v - x1, get<1>v - y1))
		}

		point first = p3.vertices.at(0);
		int x1 = get<0>first;
		int y1 = get<1>first;
		for (vertex v: p3.vertices) {
			v1.push_back(make_tuple(get<0>v - x1, get<1>v - y1))
		}

		vector<vertex> vertices;
		for (int i=0; i<p1.size(); i++) {
			vertices.push_back(make_tuple(p2.at(i), p3.at(i), p1.at(i)));
		}

		vector<tuple<int, int>> edges;
		for (edge e: p1.edges) {
			if(find(p2.edges.begin(), p2.edges.end(), e) != p2.edges.end()) {
			    if(find(p3.edges.begin(), p3.edges.end(), e) != p3.edges.end()) {
			    	edges.push_back(e);
			    }
			}
		}

		return model(vertices, edges);
	}
};

int main() {

	vertex v1(2,2,2); //will be a set
	plane p1(1,2,3,4);
	v1.printVertex();
	p1.printNormal();
	algorithms a1;
	vertex res = a1.algorithm2Dto3D(v1, p1);
	cout<<(get<0>(res.v));

	return 0;
}