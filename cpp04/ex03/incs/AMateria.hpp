/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:40:04 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/10 23:05:07 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>
# include <string>

class	AMateria
{
public:
	// Constructors
	AMateria(void);
	AMateria(const AMateria& copy);
	AMateria(std::string const & type);

	// Destructors
	~AMateria(void);

	// Operators
	AMateria&	operator=(const AMateria& copy);

	// Utils
	std::string const &	getType(void) const; // Returns the materia type
	virtual AMateria*	clone(void) const = 0;
//	virtual void		use(ICharacter& target);
	virtual void		use(std::string target);

protected:
	std::string	type;
};

#endif
