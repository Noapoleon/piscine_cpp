/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:16:05 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 14:08:20 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Destructors
Serializer::~Serializer(void) {}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

// Constructors (private)
Serializer::Serializer(void) {}
Serializer::Serializer(const Serializer& copy) { (void)copy; }

// Operators
Serializer& Serializer::operator=(const Serializer& copy)
{ (void)copy; return (*this); }
