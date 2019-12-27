#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <fstream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Segment_2 Segment_2;
typedef std::vector<Point_2> Points;
typedef K::Line_2 Line_2;
typedef K::Intersect_2 Intersect_2;

using namespace std;


int main(int argc, char** argv)
{
	std::ifstream in;
	std::ofstream out;
	in.open(argv[1]);
	Points points;
	std::istream_iterator<Point_2> input_begin(in);
	std::istream_iterator<Point_2> input_end;
	while(input_begin != input_end)
	{
		points.push_back(*input_begin);
		input_begin++;
	}
	int size = points.size();
	Line_2 lin(points[points.size()-1],points[points.size()-2]);
	int i;
	points.pop_back();
	points.pop_back();
	Points points2;
	CGAL::convex_hull_2(points.begin(), points.end(), std::back_inserter(points2));
	for(i=0;i<points2.size();i++)
	{
		Segment_2 seg(points2[i], points2[(i+1)%points2.size()]);
		CGAL::cpp11::result_of<Intersect_2(Segment_2, Line_2)>::type
		result = intersection(seg, lin);
		if(result) 
		{
			if(const Segment_2* s = boost::get<Segment_2>(&*result)) 
			{
				std::cout << *s << std::endl;
			} 
			else 
			{
				const Point_2* p = boost::get<Point_2 >(&*result);
				std::cout << *p << std::endl;
			}
		}
	}

	
	return 0;
}