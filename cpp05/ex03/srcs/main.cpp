#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define COL_PARA	"\e[34;7;1m"
#define COL_TEST	"\e[4;3;1m"
#define COL_ERR		"\e[31;1m"
#define COL_RST		"\e[0m"

void	show_err(const std::exception& e)
{
	std::cout << COL_ERR "error -> " << e.what() << COL_RST << std::endl;
}

template <typename T>
void	try_form(T form, int b_grade)
{
	if (b_grade == -1)
	{
		try {
			Bureaucrat	b("Miguel", 1);

			b.executeForm(form);
		} catch (std::exception& e) {
			show_err(e);
		}
		return ;
	}
	try {
		Bureaucrat	b("Miguel", b_grade);

		b.signForm(form);
		b.executeForm(form);
		form.execute(b);
	} catch (std::exception& e) {
		show_err(e);
	}
}

int	main(void)
{
	// Init rng
	srand(time(NULL));

	try
	{
		Intern		someRandomIntern;
		AForm		*form;

		form = someRandomIntern.makeForm("robotomy request", "Bender");
		try_form(*(static_cast<RobotomyRequestForm*>(form)), 1);
		delete form;

		form = someRandomIntern.makeForm("presidential pardon", "Bender");
		try_form(*(static_cast<PresidentialPardonForm*>(form)), 1);
		delete form;

		form = someRandomIntern.makeForm("shrubbery creation", "Bender");
		try_form(*(static_cast<ShrubberyCreationForm*>(form)), 1);
		delete form;
	} catch (const std::exception& e) {
		show_err(e);
	}

	return (0);
}
