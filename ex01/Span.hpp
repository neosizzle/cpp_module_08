#ifndef __SPAN__H__
#define __SPAN__H__
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int		_size;
		unsigned int		_elems_stored;
		std::vector<int>	_vect;

	public:
		Span();
		Span(unsigned int size);
		Span(const Span &span);
		~Span();

		Span &operator = (const Span &span);

		void	addNumber(int number);
		std::vector<int>::iterator	shortestSpan();//sort then find min diff
		std::vector<int>::iterator	largestSpan();//minmax

		class IndexOverflowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
					{
						return "Index access out of bounds";
					}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
					{
						return "Span does not exist";
					}
		};
};

#endif  //!__SPAN__H__