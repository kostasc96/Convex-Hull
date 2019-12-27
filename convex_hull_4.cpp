#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <fstream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Projection_traits_yz_3.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/point_generators_3.h>

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
	CGAL::convex_hull_2(points.begin(),points.end(), std::back_inserter(points2), K());
	for(int i=0;i<points2.size();i++)
	{
		cout<<points2[i]<<endl;
	}
	
	return 0;
}