/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:59:21 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/20 01:20:12 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP


template<typename T>
static void	parse(std::string str, T& container)
{
	std::ostringstream	errOut;
	std::istringstream	stream(str);
	unsigned int		x;

	// Validate format
	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]) && str[i] != ' ')
		{
			errOut << "Bad character at index " << i << ": '" << str[i] << "'";
			throw std::runtime_error(errOut.str());
		}
	}

	// Push integers
	while (stream.good() && !stream.eof())
	{
		stream >> x;
		if (stream.fail())
			throw std::runtime_error("Failed to read integer from stream");
		container.push_back(x);
	}
}

// Utils
template<typename T>
void	PmergeMe::sort(std::string str, T& container)
{
	parse(str, container);
}


#endif // PMERGE_ME_TPP
