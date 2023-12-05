/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:57:10 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/05 16:13:50 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

typedef enum e_scalarType
{
	SC_CHAR
	SC_INT,
	SC_FLOAT,
	SC_DOUBLE,
	SC_INVALID
} t_scalarType;
typedef struct s_scalar
{
	t_scalarType	type;
	char			c;
	int				i;
	float			f;
	double			d;
} t_scalar;

class ScalarConverter
{
public:
	// Utils
	static void	convert(const std::string& format);
private:
	// Constructor
	ScalarConverter(void);
};

#endif // SCALAR_CONVERTER_HPP
