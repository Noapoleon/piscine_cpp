/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:15:10 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 14:01:20 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>

struct Data
{
	std::string data;
};

class Serializer
{
public:
	// Destructors
	~Serializer(void);

	// Utils
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
private:
	// Constructors
	Serializer(void);
	Serializer(const Serializer& copy);

	// Operators
	Serializer& operator=(const Serializer& copy);
};

#endif // SERIALIZER_HPP
