/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:59:24 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/29 23:03:04 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
public:
	// Constructors
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat(const std::string& name, int grade);

	// Destructors
	~Bureaucrat(void);

	// Operators
	Bureaucrat&	operator=(const Bureaucrat& copy);

	// Getters / Setters
	int			getGrade(void) const;
	std::string	getName(void) const;

	// Utils
	void	incrementGrade(void);
	void	decrementGrade(void);
	void	validateGrade(const int g) const;
	void	signForm(AForm& f) const;
	void	executeForm(const AForm& f) const;


	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	// Constants
	static const int	maxGrade = 1;
	static const int	minGrade = 150;

private:
	const std::string	_name;
	int					_grade;
};

// Stream operators
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
