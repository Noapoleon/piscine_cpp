/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:05:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 21:10:19 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Cure : virtual public AMateria
{
public:
	// Constructors
	Cure(void);
	Cure(const Cure& copy);

	// Destructors
	~Cure(void);

	// Operators
	Cure&	operator=(const Cure& copy);

	// Utils
	AMateria*	clone(void) const;
	void		use(ICharacter& target);
};

#endif
