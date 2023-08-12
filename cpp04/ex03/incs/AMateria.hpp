/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:40:04 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 21:21:08 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class	AMateria
{
public:
	// Constructors
	AMateria(void);
	AMateria(const AMateria& copy);
	AMateria(std::string const & type);

	// Destructors
	virtual ~AMateria(void);

	// Operators
	AMateria&	operator=(const AMateria& copy);

	// Utils
	std::string const &	getType(void) const; // Returns the materia type
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string	type;
};

#endif
