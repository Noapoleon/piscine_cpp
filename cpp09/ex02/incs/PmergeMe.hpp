/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:45:04 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/20 20:23:47 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

class PmergeMe
{
public:
	// Destructors
	~PmergeMe(void);

	// Utils
	template<typename T>
	static void	sort(const std::string& str, T& container);
private:
	// Constructors (private)
	PmergeMe(void);
	PmergeMe(const PmergeMe& copy);

	// Operators (private)
	PmergeMe& operator=(const PmergeMe& copy);
};

#include "PmergeMe.tpp"

#endif // PMERGE_ME_HPP

