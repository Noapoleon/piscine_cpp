/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:57 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/07 12:02:57 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int	main(void)
{
	// ScalarConverter sc1; // Won't compile

	ScalarConverter::convert("a");
	return (0);
}
