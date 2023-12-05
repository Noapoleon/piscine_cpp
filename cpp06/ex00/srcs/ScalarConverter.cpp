/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:56:38 by nlegrand          #+#    #+#             */
/*   Updated: 2023/12/05 17:53:20 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int	ft_isprint(char c)
{
	return (c >= ' ' && c <= 126);
}

static t_scalarType	getScalarType(const std::string& format)
{
	if (
	return (SC_INVALID);
}

// Utils
void	ScalarConverter::convert(const std::string& format)
{
	t_scalar	scalar;

	scalar = getScalarType(format);
}
