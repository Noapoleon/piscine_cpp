/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:10:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/06 16:02:19 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

// Destructors
Point::~Point(void) {}

// Operators
Point&	Point::operator=(const Point& copy)
{
	(void)copy;
	return (*this);
}

// Utils
const Fixed&	Point::getX() const
{
	return (this->_x);
}
const Fixed&	Point::getY() const
{
	return (this->_y);
}
