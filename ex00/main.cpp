#include "easyfind.hpp"
#include <vector> 
#include <deque> 
#include <array> 
#include <iostream>
int	main()
{
	std::vector<int> vect;

	vect.push_back(1); 
	vect.push_back(2); 
	vect.push_back(3); 
	vect.push_back(4);

	std::vector<int>::iterator found = easyfind(vect, 1);
	std::cout << *found << "\n";

	std::array<int, 4> arr;

	arr[0] = 123; 
	arr[1] = 4321; 
	arr[2] = 12; 
	arr[3] = 69;

	std::array<int, 4>::iterator found2 = easyfind(arr, 123);
	std::cout << *found2 << "\n";

	try
	{
		std::deque<int> deq;

		deq.push_back(1); 
		deq.push_back(2); 
		deq.push_back(3); 
		deq.push_back(4);

		std::deque<int>::iterator found3 = easyfind(deq, 123);
		std::cout << *found3 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
