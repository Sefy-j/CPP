/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:20:57 by jlopez-f          #+#    #+#             */
/*   Updated: 2024/08/20 00:52:13 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>

class RPN
{
	public:

		static int	calculateExpression(std::string const expression);

	private:

		static std::stack<int>	_numbers;

		RPN(void);
		RPN(const RPN &other);
		~RPN(void);

		RPN			&operator=(const RPN &other);

		static int	operate(long long int a, long long int b, char oper);

		static bool	printerror(std::string const err);
};

#endif
