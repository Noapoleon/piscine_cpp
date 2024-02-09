/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:26:09 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/09 17:34:22 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <set>

class Span {
public:
	// Constructors
	Span(void);
	Span(const Span& copy);
	Span(size_t size);

	// Destructors
	~Span(void);

	//Operators
	Span&	operator=(const Span& copy);

	// Utils
	size_t	getSize(void) const;
	void	addNumber(int n);
	size_t	shortestSpan(void) const;
	size_t	longestSpan(void) const;
	void	show(void) const;
	
	// Exceptions
	class SpanFullException : public std::exception
	{ virtual const char* what(void) const throw(); };
	class SpanTooSmallException : public std::exception
	{ virtual const char* what(void) const throw(); };

private:
	std::multiset<int>	_data;
	size_t				_size;
};

#endif // SPAN_HPP
