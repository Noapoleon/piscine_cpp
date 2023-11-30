/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/11/30 14:57:42 by nlegrand         ###   ########.fr       */
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
	std::string	getTarget(void) const;

	// Utils
	void	execute(const Bureaucrat& executor) const;

	// Constants
	static const int	gradeSign = 25;
	static const int	gradeExec = 5;
private:
	std::string	_target;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
