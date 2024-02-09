/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:31:34 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/09 17:35:32 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define DEFAULT_SPAN_SIZE	1024

// Constructors
Span::Span(void) : _size(DEFAULT_SPAN_SIZE) {}
Span::Span(const Span& copy)
{
	*this = copy;
}
Span::Span(size_t size) : _size(size) {}

// Destructors
Span::~Span(void) {}

//Operators
Span&	Span::operator=(const Span& copy)
{
	if (this == &copy)
		return (*this);
	_size = copy._size;
	for (std::multiset<int>::const_iterator it = _data.begin(); it != _data.end(); ++it)
		this->addNumber(*it);
	return (*this);
}

// Utils
size_t	Span::getSize(void) const
{ return (_size); }
void	Span::addNumber(int n)
{
	if (_data.size() + 1 > _size)
		throw SpanFullException();
	_data.insert(n);
}
//shortestSpan()
size_t	Span::shortestSpan(void) const
{
	size_t								shortest;
	int									prev;
	std::multiset<int>::const_iterator	it;

	if (_data.size() < 2)
		throw SpanTooSmallException();
	it = _data.begin();
	prev = *(it++);
	shortest = *it - prev;
	while (it != _data.end() && shortest != 0)
	{
		if (static_cast<size_t>(*it - prev) < shortest)
			shortest = static_cast<size_t>(*it - prev);
		prev = *it;
		++it;
	}
	return (shortest);
}
size_t	Span::longestSpan(void) const
{
	if (_data.size() < 2)
		throw SpanTooSmallException();
	return (*(_data.rbegin()) - *(_data.begin()));
}
void	Span::show(void) const
{
	std::cout << "Span size: " << _size << std::endl;
	std::cout << "Elements:";
	for (std::multiset<int>::const_iterator it = _data.begin(); it != _data.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

// Exceptions
const char* Span::SpanFullException::what(void) const throw()
{ return ("span full"); }
const char* Span::SpanTooSmallException::what(void) const throw()
{ return ("span too small for operation"); }
