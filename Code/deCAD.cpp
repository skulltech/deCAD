// #include <iostream>
// #include <fstream>
// #include <tuple>
// #include <vector>
// #include <algorithms.h>

// using namespace std;




// int main(){
// 	float d1,d2,d3,d4;
// 	int e1,e2;
// 	int num;
// 	//--------------algorithm one check----------------------
// 	ifstream infile;
// 	infile.open("input.txt");

// 	// take vertex inputs
// 	infile >> num;
// 	vector<vertex> vertices;
//  	for(int i=0;i<(num);i++){
// 		infile>>d1>>d2>>d3>>d4;
// 		vertices.push_back(vertex(d2,d3,d4));
// 	}

// 	// take edges input
// 	infile >> num;
// 	vector<tuple<int,int>> edges;
//  	for(int i=0;i<(num);i++){
// 		infile>>e1>>e2;
// 		edges.push_back(make_tuple(e1,e2));
// 	}

// 	// take plane input
// 	infile>>d1>>d2>>d3>>d4;
// 	plane pl(d1,d2,d3,d4);

// 	infile.close();
// 	model m1(vertices,edges);
// 	algorithms a1;
// 	model m2 = a1.model_to_projections(m1, pl);

//    QApplication a(argc, argv);
//    QLabel l;
//    QPicture pi;
//    QPainter p(&pi);

//    p.setRenderHint(QPainter::Antialiasing);
//    p.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
//    // p.drawLine(0, 0, 200, 200);
   
//    float x, y, prev_x=0, prev_y=0 ;

//    for (int i = 1; i < SIZE; ++i){
//       x = i*STEP;
//       y = sin(x);
//       p.drawLine(FACTOR*prev_x, FACTOR*prev_y, FACTOR*x, FACTOR*y);

//       prev_x = x;
//       prev_y = y;
//    }

//    p.end(); // Don't forget this line!

//    l.setPicture(pi);
//    l.show();
//    return a.exec();



// 	for (vertex i: m2.vertices){
// 		cout<<(get<0>(i.v))<<" "<<(get<1>(i.v))<<" "<<(get<2>(i.v))<<endl;
// 	}

// 	//--------------------------algorithm one check-------------------

// 	//------------------------- algorithm two check---------------------

// 	infile.open("input2.txt");

// 	infile >> num;

// 	vector<point> points1;
//  	for(int i=0;i<(num);i++){
// 		infile>>d1>>d2;
// 		points1.push_back(point(d1, d2));
// 	}

// 	infile >> num;

// 	vector<tuple<int,int>> edges1;
//  	for(int i=0;i<(num);i++){
// 		infile>>e1>>e2;
// 		edges1.push_back(make_tuple(e1,e2));
// 	}

// 	projection p1(points1, edges1);

// 	infile >> num;

// 	vector<point> points2;
//  	for(int i=0;i<(num);i++){
// 		infile>>d1>>d2;
// 		points2.push_back(point(d1, d2));
// 	}

// 	infile >> num;

// 	vector<tuple<int,int>> edges2;
//  	for(int i=0;i<(num);i++){
// 		infile>>e1>>e2;
// 		edges2.push_back(make_tuple(e1,e2));
// 	}

// 	projection p2(points2, edges2);


// 	vector<point> points3;
//  	for(int i=0;i<(num);i++){
// 		infile>>d1>>d2;
// 		points3.push_back(point(d1, d2));
// 	}

// 	infile >> num;

// 	vector<tuple<int,int>> edges3;
//  	for(int i=0;i<(num);i++){
// 		infile>>e1>>e2;
// 		edges3.push_back(make_tuple(e1,e2));
// 	}

// 	projection p3(points3, edges3);
// 	infile.close();

// 	model m3 = a1.projections_to_model(p1, p2, p3);
// 	for (vertex i: m3.vertices){
// 		cout<<(get<0>(i.v))<<" "<<(get<1>(i.v))<<" "<<(get<2>(i.v))<<endl;
// 	}

// }

#include <iostream>  

void MultiplyWithOutAMP() {  

   int aMatrix[3][2] = {{1, 4}, {2, 5}, {3, 6}};  
   int bMatrix[2][3] = {{7, 8, 9}, {10, 11, 12}};  
   int product[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};  

   for (int row = 0; row < 3; row++) {  
       for (int col = 0; col < 3; col++) {  
           // Multiply the row of A by the column of B to get the row, column of product.  
           for (int inner = 0; inner < 2; inner++) {  
               product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];  
           }  
           std::cout << product[row][col] << "  ";  
       }  
       std::cout << "\n";  
   }
}  

int main() {  
   MultiplyWithOutAMP();  
   return 0;
}  