/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:25:41 by jlopez-f          #+#    #+#             */
/*   Updated: 2024/08/21 02:24:14 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <climits>
#include <cstdlib>

std::stack<int>	RPN::_numbers;

RPN::RPN(void) {}

RPN::RPN(const RPN &other) { *this = other; }

RPN::~RPN(void) {}

RPN		&RPN::operator=(const RPN &other) { (void)other; return (*this); }

int		RPN::calculateExpression(std::string const expr)
{
	int		a = 0, b = 0;

	_numbers = std::stack<int>();
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (isdigit(expr[i]))
		{
			if (i != 0 && isdigit(expr[i - 1]))
				return (printerror("only single digit numbers are valid."));
			_numbers.push(expr[i] - '0');
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
		{
			if (_numbers.size() < 2)
				return (printerror("not enough numbers to calculate operation."));
			b = _numbers.top();
			_numbers.pop();
			a = _numbers.top();
			_numbers.pop();
			_numbers.push(operate(static_cast<long long int>(a), static_cast<long long int>(b), expr[i]));
		}
		else if (expr[i] == ' ')
		{
			if (i == 0 || expr[i - 1] == ' ')
				return (printerror("extraneous space in expression."));
		}
		else
			return (printerror("extraneous character in expression."));
	}
	if (_numbers.size() != 1)
		return (printerror("not enough operators to calculate operation."));
	std::cout << _numbers.top() << std::endl;
	return (0);
}

int		RPN::operate(long long int a, long long int b, char oper)
{
	long long int	result = 0;

	if (oper == '+')
		result = a + b;
	else if (oper == '-')
		result = a - b;
	else if (oper == '*')
		result = a * b;
	else if (oper == '/')
		result = a / b;
	if (result > INT_MAX || result < INT_MIN)
	{
		printerror("operation result is out of limits.");
		exit(-1);
	}
	return (static_cast<int>(result));
}

bool	RPN::printerror(std::string const err)
{
	std::cerr << "Error: " << err << std::endl;
	return (false);
}
