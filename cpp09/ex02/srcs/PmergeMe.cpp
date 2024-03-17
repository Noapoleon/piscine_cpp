/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:55:14 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/17 20:25:46 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Destructors
PmergeMe::~PmergeMe(void) {}

void	validateFormat(const std::string& str)
{
	std::ostringstream	out;

	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]) && !isspace(str[i]))
		{
			out << "Bad character at index " << i << ": '" << str[i] << "'";
			throw std::runtime_error(out.str());
		}
	}
}

// Utils
void	PmergeMe::sort(std::string str)
{
	std::list<unsigned int> lst;
	std::istringstream		stream(str);
	unsigned int			x;

	validateFormat(str);
	while (stream.good() && !stream.eof())
	{
		stream >> x;
		if (stream.fail())
			throw std::runtime_error("Failed to read integer from stream");
		lst.push_back(x);
	}
	
	// show (remove)
	for (std::list<unsigned int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Constructors (private)
PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe& copy) { (void)copy; }

// Operators (private)
PmergeMe& PmergeMe::operator=(const PmergeMe& copy) { (void)copy; return (*this); }
