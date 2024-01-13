/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:58:17 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/10 15:43:55 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template < typename T >
void	iter(T* arr, size_t size, void (*fun)(T&))
{
	for (size_t i = 0; i < size; ++i)
		fun(arr[i]);
}

#endif // ITER_HPP
