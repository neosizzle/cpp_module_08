#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Span.hpp"

int	main()
{
	Span sp = Span(5);
	std::vector<int> vector;
	vector.push_back(2000);
	vector.push_back(250);
	vector.push_back(-2200);
	vector.push_back(249);
	sp.addNumber(vector.begin(), vector.end());
}
