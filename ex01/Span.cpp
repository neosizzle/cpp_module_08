#include "Span.hpp"

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
Span::Span(){}

Span & Span::operator = (const Span &span)
{
	this->_size = span._size;
	this->_elems_stored = span._elems_stored;
	this->_vect = span._vect;
	return *this;	
}