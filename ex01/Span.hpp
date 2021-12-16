#ifndef __SPAN__H__
#define __SPAN__H__
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
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
		int	shortestSpan();
		int	longestSpan();

		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end)
		{
			int	sizeLeft;

			sizeLeft = this->_size - this->_elems_stored;
			if (sizeLeft <= 0 || std::distance(begin, end) > sizeLeft)
				throw Span::IndexOverflowException();
			this->_vect.insert(this->_vect.begin(), begin, end);
			this->_elems_stored += std::distance(begin, end);
		}

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