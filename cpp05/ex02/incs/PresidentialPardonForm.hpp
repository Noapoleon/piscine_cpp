/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:44 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/30 02:11:41 by nlegrand         ###   ########.fr       */
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
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& c);

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
std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& f);

#endif // PRESIDENTIAL_PARDON_FORM_HPP
