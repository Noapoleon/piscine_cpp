/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:55:52 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/17 18:38:53 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"

class Dog : public AAnimal
{
public:
	// Constructors
	Dog(void);
	Dog(const Dog& copy);

	// Destructors
	~Dog(void);

	// Operator
	Dog&	operator=(const Dog& copy);

	// Utils
	void		makeSound(void) const;

private:
	Brain	*brain;
};

#endif
