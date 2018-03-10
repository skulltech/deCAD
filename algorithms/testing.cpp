#include <iostream>
#include <set>
#include <tuple>
#include <edge.h>

using namespace std;

class edge{

	public:
	float length;
	tuple <vertex,vertex> e;
	
	void makeEdge(vertex v1, vertex v2){
		e = make_tuple (v1,v2);
	}

	void printEdge(){
		cout<<get<0>(get<0>(e))-get<0>(get<1>(e))<<"i^ + "<<get<1>(get<0>(e))-get<1>(get<1>(e))<<"j^ +"<<get<2>(get<0>(e))-get<2>(get<1>(e))<<"k^ "<<endl;
	}

};

class vertex{
	public:
	tuple <float,float,float> v;

	vertex(float a, float b, float c){
		v = make_tuple(a,b,c);
	}
	void printVertex(){
		cout<<(get<0>(v))<<", "<<(get<1>(v))<<", "<<(get<2>(v))<<endl;
	}
};

class plane {
	public:
	float a,b,c,d; //the equation of plane is ax+by+cz+d=0;
	tuple <float,float,float> normal;

	plane(float a1,float b1, float c1, float d1){
		a=a1;b=b1;c=c1;d=d1;
	}

	void printNormal(){
		cout<<get<0>(get<0>(normal))-get<0>(get<1>(normal))<<"i^ + "<<get<1>(get<0>(normal))-get<1>(get<1>(normal))<<"j^ +"<<get<2>(get<0>(normal))-get<2>(get<1>(normal))<<"k^ "<<endl;
	}

	float squareNormal(){
		return (a*a+b*b+c*c); 
	}
};

class algorithms {
    
	protected:
	/**
	* Algorithm implementation for converting given 2D projections
	* into a 3D model.
	*/
	vertex algorithm2Dto3D(vertex v, edge e, plane p){

		int temp1=(get<0>(p.getNormal()))*(get<0>(v.v))+(get<1>(p.getNormal()))*(get<1>(v.v))+(get<2>(p.getNormal()))*(get<2>(v.v));
		int temp2=(p.squareNormal())

		vertex((temp1/temp2)*(get<0>(p.normal)),(temp1/temp2)*(get<1>(p.normal)),(temp1/temp2)*(get<2>(p.normal))) projw;
		vertex((get<0>(v.v)-get<0>(projw.v)),(get<1>(v.v)-get<1>(projw.v)),(get<2>(v.v)-get<2>(projw.v))) q;

		return q;				
	}

	/**
	* Algorithm implementation for converting given 3D model 
	* into a 2D projection on the given plane.
	*/
	void algorithm3Dto2D(){

	}
};

int main(){

	edge e1; //will be a set
	vertex v1; //will be a set
	plane p1;

	algorithms a1;
	vertex res = a1.algorithm2Dto3D(v1, e1, p1);

	cout<<"resultant vertex is";

	return 0;
}