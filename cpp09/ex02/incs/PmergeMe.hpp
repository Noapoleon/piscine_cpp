/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:45:04 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/17 20:26:19 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

// Containers
#include <list> // remove later, testing

class PmergeMe
{
public:
	// Destructors
	~PmergeMe(void);

	// Utils
	static void	sort(std::string str);
private:
	// Constructors (private)
	PmergeMe(void);
	PmergeMe(const PmergeMe& copy);

	// Operators (private)
	PmergeMe& operator=(const PmergeMe& copy);
};

#endif // PMERGE_ME_HPP

