/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/02 22:22:13 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"


class	PresidentialPardonForm : public AForm
{
public:
	// Constructors
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& c);
	PresidentialPardonForm(const std::string& target);

	// Destructors
	~PresidentialPardonForm(void);

	// Operators

	// Getters/Setters

	// Utils
	void	execute(const Bureaucrat& executor) const;

	// Constants
	static const int	gradeSign = 25;
	static const int	gradeExec = 5;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
