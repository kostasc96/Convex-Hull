#include <iostream>
#include <cstdlib>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2> Points;

using namespace std;


int main()
{
	Points result;

	std::istream_iterator< Point_2 >  input_begin(std::cin);
	std::istream_iterator< Point_2 >  input_end;
	
	CGAL::convex_hull_2(input_begin, input_end, std::back_inserter(result));
	std::cout << result.size() << std::endl;
	
	int i;
	for(i=0;i<result.size();i++)
	{
		cout<<result[i]<<endl;
	}
	
	return 0;
}