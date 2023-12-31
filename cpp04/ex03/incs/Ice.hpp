/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:05:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 22:53:01 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Ice : virtual public AMateria
{
public:
	// Constructors
	Ice(void);
	Ice(const Ice& copy);

	// Destructors
	~Ice(void);

	// Operators
	Ice&	operator=(const Ice& copy);

	// Utils
	AMateria*	clone(void) const;
	void		use(ICharacter& target);
};

#endif
