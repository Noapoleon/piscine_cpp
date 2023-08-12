/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:08:53 by nlegrand          #+#    #+#             */
/*   Updated: 2023/08/12 23:34:11 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource(void)
{
	this->_initSlots();
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	this->_initSlots();
	*this = copy;
}

// Destructors
MateriaSource::~MateriaSource(void)
{
	this->_deleteInv();
}

// Operators
MateriaSource&	MateriaSource::operator=(const MateriaSource& copy)
{
	if (this == &copy)
		return (*this);

	// Destroy previous stuff
	this->_deleteInv();

	// Copy new stuff
	for (int i = 0; i < MATERIASOURCE_INV_SIZE; ++i)
		if (copy._inv[i])
			this->_inv[i] = copy._inv[i]->clone();
	return (*this);
}

// Utils
void		MateriaSource::learnMateria(AMateria* m)
{
	int	first_empty = -1;

	if (m == NULL)
	{
		std::cout << MATERIASOURCE_INV_ERROR "Invalid materia!" << std::endl;
		return;
	}
	for (int i = 0; i < MATERIASOURCE_INV_SIZE; ++i)
		if (this->_inv[i] == NULL)
		{
			first_empty = i;
			break;
		}
	if (first_empty == -1)
	{
		std::cout << MATERIASOURCE_INV_ERROR "Inventory is full!" << std::endl;
		return;
	}
	this->_inv[first_empty] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MATERIASOURCE_INV_SIZE; ++i)
	{
		if (this->_inv[i] && this->_inv[i]->getType() == type)
			return (this->_inv[i]->clone());
	}
	std::cout << MATERIASOURCE_INV_ERROR "Unknown materia!" << std::endl;
	return (NULL);
}

void MateriaSource::forgetMateria(int idx)
{
	if (this->_isBadSlot(idx))
		return;
	delete this->_inv[idx];
	this->_inv[idx] = NULL;
}

void	MateriaSource::displayInfo(void) const
{
	std::cout << "| MateriaSource info |" << std::endl;
	for (int i = 0; i < MATERIASOURCE_INV_SIZE; ++i)
	{
		std::cout << "Item slot " << i << ": ";
		if (this->_inv[i])
			std::cout << this->_inv[i]->getType() << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
}

// Private utils
void	MateriaSource::_deleteInv(void)
{
	for (int i = 0; i < MATERIASOURCE_INV_SIZE; ++i)
		delete this->_inv[i];
	this->_initSlots();
}

void	MateriaSource::_initSlots(void)
{
	for (int i = 0; i < MATERIASOURCE_INV_SIZE; ++i)
		this->_inv[i] = NULL;
}

int	MateriaSource::_isBadSlot(int idx)
{
	if (idx < 0 || idx >= MATERIASOURCE_INV_SIZE)
	{
		std::cout << MATERIASOURCE_INV_ERROR "Invalid inventory slot!" << std::endl;
		return (1);
	}
	if (this->_inv[idx] == NULL)
	{
		std::cout << MATERIASOURCE_INV_ERROR "Inventory slot empty!" << std::endl;
		return (1);
	}
	return (0);
}
