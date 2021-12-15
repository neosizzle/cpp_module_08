#include "easyfind.hpp"
#include <vector> 
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
	return 0;
}
