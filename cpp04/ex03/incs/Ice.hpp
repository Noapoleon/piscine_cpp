/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:05:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 23:09:42 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

class	Ice : virtual public AMateria
{
	// Constructors
	Ice(void);
	Ice(const Ice& copy);

	// Destructors
	~Ice(void);

	// Operators
	Ice&	operator=(const Ice& copy);

	// Utils
	virtual	Ice*	clone(void) const;
};

#endif
