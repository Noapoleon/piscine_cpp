/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:59:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/17 16:16:50 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str			= "HI THIS IS BRAIN";
	if (str.empty())
		return (1);
	std::string	*stringPTR	= &str;
	std::string	&stringREF	= str;

	std::cout << "Addr str -------> " << &str << std::endl;
	std::cout << "Addr stringPTR -> " << stringPTR << std::endl;
	std::cout << "Addr stringREF -> " << &stringREF << std::endl << std::endl;
	// Correction
	//std::cout << "Addr stringREF -> " << &stringREF << std::endl << std::endl;

	std::cout << "Value str -------> " << str << std::endl;
	std::cout << "Value stringPTR -> " << *stringPTR << std::endl;
	std::cout << "Value stringREF -> " << stringREF << std::endl;
	// Correction
	//std::cout << "Value stringREF -> " << *stringREF << std::endl;
	return (0);
}
