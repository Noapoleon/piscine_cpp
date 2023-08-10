/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:06:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 21:52:05 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define BRAIN_CAPACITY 100

#include <iostream>
#include <string>

class	Brain
{
public:
	// Constructors
	Brain(void);
	Brain(const Brain& copy);

	// Destructors
	~Brain(void);

	// Operators
	Brain& operator=(const Brain& copy);

private:
	std::string	ideas[BRAIN_CAPACITY];
};

#endif
