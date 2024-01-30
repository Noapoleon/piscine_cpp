/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/30 02:19:51 by nlegrand         ###   ########.fr       */
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
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& c);

	// Utils
	std::string		getTarget(void) const;
	virtual void	execAction(void) const;

	// Constants
	static const std::string	defaultName;
	static const int			defaultGradeSign = 72;
	static const int			defaultGradeExec = 45;
	static const std::string	defaultTarget;

private:
	const std::string	_target;
};

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& f);

#endif // ROBOTOMY_REQUEST_FORM_HPP
