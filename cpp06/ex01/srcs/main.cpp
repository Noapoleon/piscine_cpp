/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:57 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 13:35:22 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>
#include "Serializer.hpp"

int	main(void)
{
	Data		d;
	uintptr_t	raw;
	Data		*dd;

	d.data = "Bonjour";
	std::cout << "Data before serialization: " << d.data << std::endl;

	raw = Serializer::serialize(&d);
	std::cout << "data pointer in Data* form: " << &d << std::endl;
	std::cout << "Raw data pointer in uintptr_t form (dec): " << raw << std::endl;
	std::cout << "Raw data pointer in uintptr_t form (hex): " << std::hex << raw << std::dec << std::endl;

	dd = Serializer::deserialize(raw);
	std::cout << "Data after serialization: " << dd->data << std::endl;

	//Serializer s; // Won't compile

	return (0);
}
