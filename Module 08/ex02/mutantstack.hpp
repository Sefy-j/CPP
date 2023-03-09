/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:20:57 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/21 14:26:41 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		~MutantStack(void) {}

		MutantStack	&operator=(const MutantStack &other)
		{
			if (this != &other)
				*this = other;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator 				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void) { return this->c.begin(); };
		const_iterator			cbegin(void) const { return this->c.cbegin(); };

		iterator				end(void) { return this->c.end(); };
		const_iterator			cend(void) const { return this->c.cend(); };

		reverse_iterator		rbegin(void) { return this->c.rbegin(); };
		const_reverse_iterator	crbegin(void) const { return this->c.crbegin(); };

		reverse_iterator		rend(void) { return this->c.rend(); };
		const_reverse_iterator 	crend(void) const { return this->c.crend(); };
};

#endif
