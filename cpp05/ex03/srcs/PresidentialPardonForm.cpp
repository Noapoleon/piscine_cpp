/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/02 22:24:31 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("DefaultPresidentialPardonName",
		false,
		PresidentialPardonForm::gradeSign,
		PresidentialPardonForm::gradeExec)
{
	_target = "DefaultTarget";
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c) :
	AForm(c)
{
	_target = c._target;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("DefaultPresidentialPardonName",
		false,
		PresidentialPardonForm::gradeSign,
		PresidentialPardonForm::gradeExec)
{
	_target = target;
}

// Destructors
PresidentialPardonForm::~PresidentialPardonForm(void) {};

// Utils
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->checkExec(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

