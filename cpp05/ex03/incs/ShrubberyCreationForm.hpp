/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/30 02:28:29 by nlegrand         ###   ########.fr       */
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
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& c);

	// Utils
	std::string		getTarget(void) const;
	virtual void	execAction(void) const;

	// Constants
	static const std::string	defaultName;
	static const int			defaultGradeSign = 25;
	static const int			defaultGradeExec = 5;
	static const std::string	defaultTarget;

private:
	const std::string	_target;
};

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& f);

#endif // PRESIDENTIAL_PARDON_FORM_HPP
