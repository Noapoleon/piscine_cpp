/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/11/29 22:19:41 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("DefaultPresidentialPardonName",
		false,
		RobotomyRequestForm::gradeSign,
		RobotomyRequestForm::gradeExec),
	_target("DefaultTarget") {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& c) :
	AForm(c),
	_target(c._target) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("DefaultPresidentialPardonName",
		false,
		RobotomyRequestForm::gradeSign,
		RobotomyRequestForm::gradeExec),
	_target(target) {}

// Destructors
RobotomyRequestForm::~RobotomyRequestForm(void) {};

// Getters/Setters
std::string	RobotomyRequestForm::getTarget(void) const
{ return (_target); }

// Utils
void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	int	random = rand() % 2;

	this->checkExec(executor);
	std::cout << "bbbbbzzzzzrrrrrrrtt...!! sscchrrrrrrtt..!! !@#$%&(T*Y#@" << std::endl;
	if (random)
		std::cout << _target << " has been robotomized! beep, boop!" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target
			<< "... Please proceed with the corpse disposal protocol."
			<< std::endl;
}

