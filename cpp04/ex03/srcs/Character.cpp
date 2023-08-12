/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:20:58 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 23:34:31 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// Constructors
Character::Character(void)
{
	this->_name = "DefaultName";
	this->_initSlots();
}

Character::Character(const Character& copy)
{
	this->_initSlots();
	*this = copy;
}

Character::Character(const std::string& name)
{
	this->_name = name;
	this->_initSlots();
}

// Destructors
Character::~Character()
{
	this->_deleteInv();
}

// Operators
Character&	Character::operator=(const Character& copy)
{
	if (this == &copy)
		return (*this);

	// Destroy previous stuff
	this->_deleteInv();

	// Copy new stuff
	this->_name = copy._name;
	for (int i = 0; i < CHARACTER_INV_SIZE; ++i)
		if (copy._inv[i])
			this->_inv[i] = copy._inv[i]->clone();
	if (copy._trash)
		this->_trash = copy._trash->clone();
	return (*this);
}

// Utils
std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int	first_empty = -1;

	if (m == NULL)
	{
		std::cout << CHARACTER_INV_ERROR "Invalid materia!" << std::endl;
		return;
	}
	for (int i = 0; i < CHARACTER_INV_SIZE; ++i)
	{
		if (this->_inv[i] == m)
		{
			std::cout << CHARACTER_INV_ERROR "Materia already equipped!" << std::endl;
			return;
		}
		if (first_empty == -1 && this->_inv[i] == NULL)
			first_empty = i;
	}
	if (first_empty == -1)
	{
		std::cout << CHARACTER_INV_ERROR "Inventory full! Materia sent to trash." << std::endl;
		this->_sendTrash(m);
		return;
	}
	this->_inv[first_empty] = m;
}

void Character::unequip(int idx)
{
	if (this->_isBadSlot(idx))
		return;
	this->_sendTrash(this->_inv[idx]);
	this->_inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->_isBadSlot(idx))
		return;
	this->_inv[idx]->use(target);
}

void	Character::displayInfo(void) const
{
	std::cout << "Name: " << this->_name << std::endl;
	for (int i = 0; i < CHARACTER_INV_SIZE; ++i)
	{
		std::cout << "Item slot " << i << ": ";
		if (this->_inv[i])
			std::cout << this->_inv[i]->getType() << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
	std::cout << "Trash slot: ";
	if (this->_trash)
		std::cout << this->_trash->getType() << std::endl;
	else
		std::cout << "empty" << std::endl;
}

// Private utils
void	Character::_deleteInv(void)
{
	for (int i = 0; i < CHARACTER_INV_SIZE; ++i)
		delete this->_inv[i];
	delete this->_trash;
	this->_initSlots();
}

void	Character::_sendTrash(AMateria *m)
{
	if (m == NULL)
		return ;
	delete this->_trash;
	this->_trash = m;
}

int	Character::_isBadSlot(int idx)
{
	if (idx < 0 || idx >= CHARACTER_INV_SIZE)
	{
		std::cout << CHARACTER_INV_ERROR "Invalid inventory slot!" << std::endl;
		return (1);
	}
	if (this->_inv[idx] == NULL)
	{
		std::cout << CHARACTER_INV_ERROR "Inventory slot empty!" << std::endl;
		return (1);
	}
	return (0);
}

void	Character::_initSlots(void)
{
	for (int i = 0; i < CHARACTER_INV_SIZE; ++i)
		this->_inv[i] = NULL;
	this->_trash = NULL;
}
