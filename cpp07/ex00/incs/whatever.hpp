/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:58:17 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/10 15:25:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template < typename T >
T	max(const T& a, const T& b)
{
	return (a >= b ? a : b);
}

template < typename T >
T	min(const T& a, const T& b)
{
	return (a <= b ? a : b);
}

template < typename T >
void	swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

#endif // WHATEVER_HPP
