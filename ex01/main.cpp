#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Span.hpp"

void print(std::string str)
{
	std::cout << str << "\n";
}

int	main()
{
	Span	sp(11000);
	int		random;
	srand(time(0));

	print("===============NOSPANEXCEPTION TEST==============");
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	print("=================================================");

	print("===============SIMPLE NUMBERS TEST==============");
		for (int i = 0; i < 5; i++)
		{
			random = (rand() % 83) - 42;
			sp.addNumber(random);
			std::cout << "Added: " << random << std::endl;
		}
		std::cout << " -> Shortest span found is: " << sp.shortestSpan() << std::endl;
		std::cout << " -> Longest span found is: " << sp.longestSpan() << std::endl;
	print("================================================");

	print("===============SIMPLE NUMBERS ITERATORS TEST==============");
		std::vector<int> vector;
		vector.push_back(2000);
		std::cout << "Added: " << 2000 << " into above span" << std::endl;
		vector.push_back(250);
		std::cout << "Added: " << 250 << " into above span" << std::endl;
		vector.push_back(-2200);
		std::cout << "Added: " << -2200 << " into above span" << std::endl;
		vector.push_back(249);
		std::cout << "Added: " << 249 << " into above span" << std::endl;
		sp.addNumber(vector.begin(), vector.end());
		std::cout << " -> Shortest span found is: " << sp.shortestSpan() << std::endl;
		std::cout << " -> Longest span found is: " << sp.longestSpan() << std::endl;
	print("================================================");

	print("===============BIG NUMBERS TEST==============");
		std::vector<int> vector2(10000, 0);
		generate(vector2.begin(), vector2.end(), rand);
		sp.addNumber(vector2.begin(), vector2.end());
		std::cout << " -> Shortest span found is: " << sp.shortestSpan() << std::endl;
		std::cout << " -> Longest span found is: " << sp.longestSpan() << std::endl;
	print("============================================");

	print("===============OVERFLOW TEST==============");
		try {
			sp.addNumber(vector2.begin(), vector2.end());
		}
		catch(std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	print("=========================================");
	return 0;
}
