/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:55:52 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/17 18:38:38 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"

class Cat : public AAnimal
{
public:
	// Constructors
	Cat(void);
	Cat(const Cat& copy);

	// Destructors
	~Cat(void);

	// Operator
	Cat&	operator=(const Cat& copy);

	// Utils
	void		makeSound(void) const;

private:
	Brain	*brain;
};

#endif
