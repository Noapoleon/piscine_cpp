/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:55:14 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/20 01:17:05 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Destructors
PmergeMe::~PmergeMe(void) {}

// Constructors (private)
PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe& copy) { (void)copy; }

// Operators (private)
PmergeMe& PmergeMe::operator=(const PmergeMe& copy) { (void)copy; return (*this); }
