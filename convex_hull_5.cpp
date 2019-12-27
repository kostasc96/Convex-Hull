#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <fstream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Projection_traits_yz_3.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/point_generators_3.h>
#include <CGAL/Timer.h>
#include <CGAL/ch_akl_toussaint.h>
#include <CGAL/ch_eddy.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K3;
typedef CGAL::Projection_traits_yz_3<K3> K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2> Points;


using namespace std;


int main(int argc, char** argv)
{
	Points points;
	int N = atoi(argv[1]);
	int R = atoi(argv[2]);
	CGAL::Random_points_on_sphere_3<Point_2> gen(R);  	
	for(int i=0; i<N; i++)
	{ 		
		points.push_back(*gen);
		gen++;
	}
	Points points2;
	CGAL::Timer clock1;
	clock1.start();
	CGAL::ch_eddy(points.begin(),points.end(), std::back_inserter(points2), K());
	clock1.stop();
	cout<<"Time for ch_eddy algorithm is: "<<clock1.time()<<" seconds."<<endl;
	CGAL::Timer clock2;
	clock2.start();
	CGAL::ch_akl_toussaint(points.begin(),points.end(), std::back_inserter(points2), K());
	clock2.stop();
	cout<<"Time for ch_akl_toussaint algorithm is: "<<clock2.time()<<" seconds."<<endl;
	
	return 0;
}
