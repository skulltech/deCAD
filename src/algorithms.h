class vertex {
	public:
	tuple <float,float,float> v;
	
	vertex(float a, float b, float c);
	void print_vertex();
};


class point {
	public:
	tuple <float,float> p;

	point();
	point(float a, float b);
	void print_vertex();
};


class plane {
	public:
	float a,b,c,d; // The equation of plane is ax+by+cz+d=0;
	tuple <float,float,float> normal;

	plane(float a1,float b1, float c1, float d1);
	void print_normal();
	float square_normal();
};

class projection {
public:
	vector<point> points;
	vector<tuple<int, int>> edges;

	projection();
	projection (vector<point> p, vector<tuple<int, int>> e);
};

class model {
public:
	vector<vertex> vertices;
	vector<tuple<int, int>> edges;

	model(vector<vertex> v, vector<tuple<int, int>> e);
};

class algorithms {
	public:
	model model_to_projections(model m, plane p);
	model projections_to_model(projection p1, projection p2, projection p3);
	bool checkEdge(vector<tuple<int,int>> edges, tuple<int,int> e);
};
