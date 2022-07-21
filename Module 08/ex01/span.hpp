/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:20:57 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/21 14:26:41 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:

		Span(const unsigned int N);
		Span(const Span &other);
		~Span(void);

		Span	&operator=(const Span &other);

		void	addNumber(const int newnb);
		void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);

		long int	shortestSpan(void);
		long int	longestSpan(void);

	private:

		Span(void);

		unsigned int		_size;
		std::vector<int>	_nbs;

		class NumberFullException: public std::exception
		{
			public:

				const char*	what(void) const throw();
		};

		class EmptySpanException: public std::exception
		{
			public:

				const char*	what(void) const throw();
		};

};

#endif
