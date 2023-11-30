/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/11/30 14:57:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"


class	ShrubberyCreationForm : public AForm
{
public:
	// Constructors
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& c);
	ShrubberyCreationForm(const std::string& target);

	// Destructors
	~ShrubberyCreationForm(void);

	// Operators

	// Getters/Setters
	std::string	getTarget(void) const;

	// Utils
	void	execute(const Bureaucrat& executor) const;

	// Constants
	static const int	gradeSign = 145;
	static const int	gradeExec = 137;
private:
	std::string	_target;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
