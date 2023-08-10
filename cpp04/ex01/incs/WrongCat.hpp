/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:55:52 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/09 23:01:04 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Constructors
	WrongCat(void);
	WrongCat(const WrongCat& copy);

	// Destructors
	~WrongCat(void);

	// Operator
	WrongCat&	operator=(const WrongCat& copy);

	// Utils
	void		makeSound(void) const;
};

#endif
