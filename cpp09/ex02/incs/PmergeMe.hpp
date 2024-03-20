/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:45:04 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/20 01:17:05 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

//template< typename T >
class PmergeMe
{
public:
	// Destructors
	~PmergeMe(void);

	// Utils
	template<typename T>
	static void	sort(std::string str, T& container);
private:
	// Constructors (private)
	PmergeMe(void);
	PmergeMe(const PmergeMe& copy);

	// Operators (private)
	PmergeMe& operator=(const PmergeMe& copy);
};

#include "PmergeMe.tpp"

#endif // PMERGE_ME_HPP

