#include "Span.hpp"

/*
** member funcs
*/
void	Span::addNumber(int number)
{
	if (this->_elems_stored >= this->_size)
		throw Span::IndexOverflowException();
	this->_vect.push_back(number);
	this->_elems_stored++;
}

int	Span::shortestSpan()//sort then find min diff
{
	std::vector<int> temp;
	std::vector<int>::iterator iter;
	int	mindiff;
	unsigned int i;
	int	curr_diff;

	if (this->_elems_stored <= 1)
		throw Span::NoSpanException();
	if (std::equal(this->_vect.begin() + 1, this->_vect.end(), this->_vect.begin()) )//all equal
		throw Span::NoSpanException();
	iter = this->_vect.begin();
	while (iter != this->_vect.end())
	{
		temp.push_back(*iter);
		++iter;
	}
	std::sort(temp.begin(), temp.end());
	i = 0;
	mindiff = abs(this->_vect.at(0) - this->_vect.at(1));
	while (++i < this->_elems_stored)
	{
		curr_diff = abs(this->_vect.at(i - 1) - this->_vect.at(i));
		if (curr_diff < mindiff)
			mindiff = curr_diff;
	}
	return mindiff;
}
int	Span::longestSpan()//minmax
{
	int	minval;
	int	maxval;

	if (this->_elems_stored <= 1)
		throw Span::NoSpanException();
	minval = *std::min_element(this->_vect.begin(),this->_vect.end());
	maxval = *std::max_element(this->_vect.begin(),this->_vect.end());
	
	if (minval == maxval)
		throw Span::NoSpanException();
	return maxval - minval;
}

/*
** OCF
*/

Span::Span() : _size(0), _elems_stored(0)
{

}
Span::Span(unsigned int size) : _size(size), _elems_stored(0)
{

}

Span::Span(const Span &span)
{
	this->_size = span._size;
	this->_elems_stored = span._elems_stored;
	this->_vect = span._vect;
}
Span::~Span(){}

Span & Span::operator = (const Span &span)
{
	this->_size = span._size;
	this->_elems_stored = span._elems_stored;
	this->_vect = span._vect;
	return *this;	
}