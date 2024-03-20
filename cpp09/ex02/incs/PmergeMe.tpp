/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:59:21 by nlegrand          #+#    #+#             */
/*   Updated: 2024/03/20 21:43:47 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP


template<typename T>
static void	parse(const std::string& str, T& container)
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
	while (stream >> x)
		container.push_back(x);
	if (stream.eof())
		return;
	if (stream.fail())
		throw std::runtime_error("Failed to read integer from stream");
}

template<typename T>
static void	flipPairs(T& container)
{
	for (typename T::size_type i = 0; i < container.size() - 1; i += 2)
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
}

template<typename T>
static T	merge(T& a, T& b)
{
	T	c;
	typename T::size_type i = 0;
	typename T::size_type j = 0;

	while (i < a.size() && j < b.size())
	{
		if (a[i] < b[j])
			c.push_back(a[i++]);
		else
			c.push_back(b[j++]);
	}

	while (i < a.size())
		c.push_back(a[i++]);
	while (j < b.size())
		c.push_back(b[j++]);
	return (c);
}

template<typename T>
static T	sortMerge(T container)
{
	// limits
	if (container.size() < 2)
		return (container);
	if (container.size() == 2 && container[0] > container[1])
		return (std::swap(container[0], container[1]), container);

	// recursion
	T	a = sortMerge(T(container.begin(), container.begin() + container.size() / 2));
	T	b = sortMerge(T(container.begin() + container.size() / 2, container.end())); // can be deleted if we use references

	// merging
	return (merge(a, b));
}

template<typename T>
static void	sortBinaryInsert(T& container, T& pend)
{
	int	l;
	int	r;
	int	m;

	for (typename T::size_type i = 0; i < pend.size(); ++i)
	{
		l = 0;
		r = container.size() - 1;
		while (l <= r)
		{
			m = l + (r - l) / 2;
			if (pend[i] < container[m])
				r = m - 1;
			else
				l = m + 1;
		}
		container.insert(container.begin() + l, pend[i]);
	}
}

// Utils
template<typename T>
void	PmergeMe::sort(const std::string& str, T& container)
{
	T	main;
	T	pend;

	// Parsing
	parse(str, container);
	if (container.size() < 2)
		return;

	// flip pairs
	flipPairs(container);

	// create main and pend chains
	for (typename T::size_type i = 0; i < container.size() - 1; i += 2)
		main.push_back(container[i + 1]);
	for (typename T::size_type i = 0; i < container.size(); i += 2)
		pend.push_back(container[i]);

	// Sorting
	container = sortMerge(main);
	sortBinaryInsert(container, pend);
}

#endif // PMERGE_ME_TPP
