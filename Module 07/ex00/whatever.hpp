/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:20:57 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 12:06:03 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &x, T &y)
{
	T	temp = x;

	x = y;
	y = temp;
}

template <typename T>
const T	&min(T const &x, T const &y)
{
	return (x <=y ? x : y);
}

template <typename T>
const T	&max(T const &x, T const &y)
{
	return (x >=y ? x : y);
}

#endif
