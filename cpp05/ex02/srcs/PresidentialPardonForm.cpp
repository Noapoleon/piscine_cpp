/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:22 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/29 22:43:10 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constants
const std::string	PresidentialPardonForm::defaultName = "PresidentForm";
const std::string	PresidentialPardonForm::defaultTarget = "TargetName";

// Constructors
PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm(defaultName, defaultGradeSign, defaultGradeExec),
	_target(defaultTarget) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c) :
	AForm(c),
	_target(defaultTarget) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm(defaultName, defaultGradeSign, defaultGradeExec),
	_target(target) {}

// Destructors
PresidentialPardonForm::~PresidentialPardonForm(void) {};

// Operators
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& c)
{
	if (this == &c)
		return (*this);
	AForm::operator=(c);
	return (*this);
}

// Utils
void	PresidentialPardonForm::execAction(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
