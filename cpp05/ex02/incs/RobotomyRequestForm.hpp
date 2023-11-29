/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/11/29 22:22:11 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"


class	RobotomyRequestForm : public AForm
{
public:
	// Constructors
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& c);
	RobotomyRequestForm(const std::string& target);

	// Destructors
	~RobotomyRequestForm(void);

	// Operators

	// Getters/Setters
	std::string	getTarget(void) const;

	// Utils
	void	execute(const Bureaucrat& executor) const;

	// Exceptions
	class	FormNotSignedException : public std::exception {
		virtual const char*	what() const throw();
	};
	
	// Constants
	static const int	gradeSign = 72;
	static const int	gradeExec = 45;
private:
	std::string	_target;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
