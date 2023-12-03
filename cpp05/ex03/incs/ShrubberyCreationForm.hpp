/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/02 23:01:02 by nlegrand         ###   ########.fr       */
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

	// Utils
	void	execute(const Bureaucrat& executor) const;

	// Constants
	static const int	gradeSign = 145;
	static const int	gradeExec = 137;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
