#ifndef __EASYFIND__H__
#define __EASYFIND__H__

#include <algorithm>
#include <stdexcept>
class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Element not found";
		}
};

//find function : https://www.cplusplus.com/reference/algorithm/find/
//typename : https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
template <typename T>
typename T::iterator	easyfind(T &cont, int item)
{
	typename T::iterator res = std::find(cont.begin(), cont.end(), item);

	if (res == cont.end())
		throw NotFoundException();
	return res;
}

#endif  //!__EASYFIND__H__