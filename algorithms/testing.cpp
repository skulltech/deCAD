#include <iostream>
#include <set>
#include <tuple>

using namespace std;

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


class edge{

	public:
	float length;
	tuple<vertex,vertex> e;
	
	// edge(vertex v1, vertex v2){
	// 	e = make_tuple(v1,v2);
	// }

	// void printEdge(){
	// 	cout<<(get<0>(get<0>(e)))-(get<0>(get<1>(e)))<<"i^ + "<<get<1>(get<0>(e))-get<1>(get<1>(e))<<"j^ +"<<get<2>(get<0>(e))-get<2>(get<1>(e))<<"k^ "<<endl;
	// }

};


class plane {
	public:
	float a,b,c,d; //the equation of plane is ax+by+cz+d=0;
	tuple <float,float,float> normal;

	plane(float a1,float b1, float c1, float d1){
		a=a1;b=b1;c=c1;d=d1;
		normal = make_tuple(a1,b1,c1);
	}

	void printNormal(){
		cout<<(get<0>(normal))<<"i^ + "<<(get<1>(normal))<<"j^ +"<<(get<2>(normal))<<"k^ "<<endl;
	}

	float squareNormal(){
		return (a*a+b*b+c*c); 
	}
};


int main(){
	cout<<"done"<<endl;
	vertex v2(1,2,3.14);
	vertex v1(2,2.71,3);

	return 0;
}