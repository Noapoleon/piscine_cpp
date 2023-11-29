/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/11/29 15:33:16 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(void) :
	_target("DefaultTarget")
{
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}
//PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c);
//PresidentialPardonForm::PresidentialPardonForm(const std::string& target);

// Destructors
PresidentialPardonForm::~PresidentialPardonForm(void) {};
