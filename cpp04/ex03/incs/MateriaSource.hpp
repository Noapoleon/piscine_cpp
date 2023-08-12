/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:04:56 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 23:27:23 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

# define MATERIASOURCE_INV_SIZE		4
# define MATERIASOURCE_INV_ERROR	"\e[31;1merror MateriaSource:\e[0m "

class MateriaSource : public IMateriaSource
{
public:
	// Constructors
	MateriaSource(void);
	MateriaSource(const MateriaSource& copy);

	// Destructors
	~MateriaSource(void);

	// Operators
	MateriaSource&	operator=(const MateriaSource& copy);

	// Utils
	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
	void		forgetMateria(int idx);
	void		displayInfo(void) const;
private:
	AMateria*	_inv[MATERIASOURCE_INV_SIZE];

	// Private utils
	void	_deleteInv(void);
	int		_isBadSlot(int idx);
	void	_initSlots(void);
};

#endif
