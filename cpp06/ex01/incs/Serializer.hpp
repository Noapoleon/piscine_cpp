/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:15:10 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/18 08:45:10 by nlegrand         ###   ########.fr       */
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
	// Utils
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
private:
	Serializer(void);
};

#endif // SERIALIZER_HPP
