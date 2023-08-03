/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:03:29 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/03 18:24:28 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	// Constructors
	Point(void);
	Point(const Point& copy);
	Point(float const x, float const y);

	// Destructors
	~Point(void);

	// Operators
	Point&	operator=(const Point& copy);

	// Utils

private:
	Fixed const	_x;
	Fixed const	_y;
};
#endif
