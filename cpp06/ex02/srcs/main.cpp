/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/18 10:15:22 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Base
{
public:
	virtual ~Base(void);
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void)
{
	Base	*tmp;
	int		r;

	tmp = NULL;
	r = rand() % 3;
	try {
		if (r == 0)
		{
			tmp = new A;
			std::cout << "Generated -> A" << std::endl;
		}
		else if (r == 1)
		{
			tmp = new B;
			std::cout << "Generated -> B" << std::endl;
		}
		else
		{
			tmp = new C;
			std::cout << "Generated -> C" << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << "Exception generate(): " << e.what() << std::endl;
	}
	return (tmp);
}

int	main(void)
{
	Base *tmp;

	srand(time(NULL));
	for (int i = 0; i < 15; ++i)
	{
		tmp = generate();
		delete tmp;
	}

	return (0);
}
