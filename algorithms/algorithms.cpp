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


class algorithms {
	public:
	/**
	* Algorithm implementation for converting given 3D model 
	* into a 2D projection on the given plane.
	*/
	vertex algo_3D_to_2D(vertex v, plane p){

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
	void algo_2D_to_3D(){

	}
};

int main(){

	vertex v1(2,2,2); //will be a set
	plane p1(1,2,3,4);
	v1.printVertex();
	p1.printNormal();
	algorithms a1;
	vertex res = a1.algorithm2Dto3D(v1, p1);
	cout<<(get<0>(res.v));

	return 0;
}