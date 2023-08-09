/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:41:12 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 23:11:34 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
public:
	// Constructors
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& copy);

	// Destructors
	virtual ~WrongAnimal(void);

	// Operator
	WrongAnimal&	operator=(const WrongAnimal& copy);

	// Utils
	std::string		getType(void) const;
	void	makeSound(void) const;
protected:
	std::string	type;
};

#endif
