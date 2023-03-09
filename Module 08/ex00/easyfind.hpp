/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:20:57 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 18:22:14 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>

class NotFoundException: public std::exception
{
	public:

		const char* what(void) const throw() { return ("Number not found"); }
};

template <typename T>
typename T::const_iterator	easyfind(T &cont, int n)
{
	typename T::const_iterator	it;

	it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw (NotFoundException());
	return (it);
}

#endif
