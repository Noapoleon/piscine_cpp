/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:22 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/02 23:04:51 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("DefaultPresidentialPardonName",
		false,
		ShrubberyCreationForm::gradeSign,
		ShrubberyCreationForm::gradeExec)
{
	_target = "DefaultTarget";
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c) :
	AForm(c)
{
	_target = c._target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("DefaultPresidentialPardonName",
		false,
		ShrubberyCreationForm::gradeSign,
		ShrubberyCreationForm::gradeExec)
{
	_target = target;
}

// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

// Getters/Setters

// Utils
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
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
	this->checkExec(executor);
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

