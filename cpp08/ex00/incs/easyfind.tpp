/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:35:06 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/21 23:26:06 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template<typename T>
typename T::iterator	easyfind(T& arr, const int n)
{
	typename T::iterator	tmp = std::find(arr.begin(), arr.end(), n);

	if (tmp != arr.end())
		return (tmp);
	else
		throw std::runtime_error("Instance not found in container");
}

#endif // EASYFIND_TPP
