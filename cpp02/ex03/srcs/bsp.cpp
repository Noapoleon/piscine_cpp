/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:03:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/06 16:10:45 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	sign(Point const p1, Point const p2, Point const p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool	bsp(Point const pt, Point const a, Point const b, Point const c)
{
	Fixed	d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(pt, a, b);
	d2 = sign(pt, b, c);
	d3 = sign(pt, c, a);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
