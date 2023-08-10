/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:41:12 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 21:41:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class	Animal
{
public:
	// Constructors
	Animal(void);
	Animal(const Animal& copy);

	// Destructors
	virtual ~Animal(void);

	// Operator
	Animal&	operator=(const Animal& copy);

	// Utils
	std::string		getType(void) const;
	virtual void	makeSound(void) const;
protected:
	std::string	type;
};

#endif
