/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:17:42 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 22:54:21 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

# define CHARACTER_INV_SIZE		4
# define CHARACTER_INV_ERROR	"\e[31;1merror Character:\e[0m "

class Character : public ICharacter
{
public:
	// Constructors
	Character(void);
	Character(const Character& copy);
	Character(const std::string& name);

	// Destructors
	~Character(void);

	// Operators
	Character&	operator=(const Character& copy);

	// Utils
	std::string const &	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
	void				displayInfo(void) const;

private:
	std::string	_name;
	AMateria*	_inv[CHARACTER_INV_SIZE];
	AMateria*	_trash;

	// Private utils
	void	_deleteInv(void);
	void	_sendTrash(AMateria *m);
	int		_isBadSlot(int idx);
	void	_initSlots(void);
};

#endif
