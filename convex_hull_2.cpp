#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <fstream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;

using namespace std;


int main(int argc, char** argv)
{
	std::ifstream in;
	std::ofstream out;
	in.open(argv[1]);
	out.open("output.txt");
	std::istream_iterator<Point_2> input_begin(in);
	std::istream_iterator<Point_2> input_end;
	std::ostream_iterator<Point_2> output(out, "\n");
	CGAL::convex_hull_2(input_begin, input_end, output);
	
	return 0;
}