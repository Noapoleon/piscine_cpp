/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:22 by nlegrand          #+#    #+#             */
/*   Updated: 2024/01/30 02:34:35 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constants
const std::string	ShrubberyCreationForm::defaultName = "ShrubberyForm";
const std::string	ShrubberyCreationForm::defaultTarget = "TargetName";

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm(defaultName, defaultGradeSign, defaultGradeExec),
	_target(defaultTarget) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c) :
	AForm(c),
	_target(defaultTarget) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm(defaultName, defaultGradeSign, defaultGradeExec),
	_target(target) {}

// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

// Operators
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& c)
{
	if (this == &c)
		return (*this);
	AForm::operator=(c);
	return (*this);
}

// Utils
std::string	ShrubberyCreationForm::getTarget(void) const
{ return (_target); }
void	ShrubberyCreationForm::execAction(void) const
{
	static const std::string	tree =
"          &&& &&  & &&\n\
      && &\\/&\\|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ '%\" & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n\
               `";

	std::ofstream	fout;
	std::string	file_name = this->getTarget() + "_shrubbery";
	try {
		fout.open(file_name.c_str());
		fout << tree << std::endl;
		if (fout.fail())
			std::cerr << "Failed to write Shrubbery tree to file :[" << std::endl;
	} catch (std::exception& e) {
		fout.close();
		std::cerr << "Failed to write Shrubbery tree to file: " << e.what() << std::endl;
	}
}

// Stream Operators
std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& f)
{
	os << f.getName() << ", form targeting " << f.getTarget()
		<< " with signing grade " << f.getGradeSign()
		<< " and executing grade " << f.getGradeExec() << " is ";
	if (f.getSigned() == false)
		os << "not ";
	os << "signed";
	return (os);
}
