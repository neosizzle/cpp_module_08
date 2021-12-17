#ifndef __MUTANTSTACK__H__
#define __MUTANTSTACK__H__
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template <class T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack<T>(){}
		MutantStack<T>(const MutantStack &MutantStack){*this = MutantStack;}
		~MutantStack<T>(){}

		MutantStack &operator = (const MutantStack &MutantStack){(void)MutantStack;return *this;}

		//the container which contains iterators are not exposed by the stack class (its protected), but can
		//still access them in code and use the underlying interator object.
		//src : https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }
};

#endif  //!__MUTANTSTACK__H__