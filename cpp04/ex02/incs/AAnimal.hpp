/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:41:12 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 22:06:46 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class	AAnimal
{
public:
	// Constructors
	AAnimal(void);
	AAnimal(const AAnimal& copy);

	// Destructors
	virtual ~AAnimal(void);

	// Operator
	AAnimal&	operator=(const AAnimal& copy);

	// Utils
	std::string		getType(void) const;
	virtual void	makeSound(void) const = 0;
protected:
	std::string	type;
};

#endif
