/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:29:37 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/21 16:46:09 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <limits.h>

int	main(void)
{
	{
		Span span(5);

		try 
		{
			span.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		span.addNumber(5);
		span.addNumber(3);
		span.addNumber(2);
		span.addNumber(INT_MAX);
		span.addNumber(INT_MIN);
		try 
		{
			span.addNumber(6);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Longest span is: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span	span(10000);
		std::vector<int>	v;

		srand(time(NULL));
		for (unsigned int i = 0; i < 10000; i++)
			v.push_back(i);
		span.addNumber(v.begin(), v.end());
		std::cout << "Longest span is: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span	span(10000);
		std::vector<int>	v;

		srand(time(NULL));
		for (unsigned int i = 0; i < 10000; i++)
			v.push_back(rand());
		span.addNumber(v.begin(), v.end());
		std::cout << "Longest span is: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span	*span = new Span(5);
		
		span->addNumber(5);
		span->addNumber(3);
		span->addNumber(17);
		span->addNumber(9);
		span->addNumber(11);
		std::cout << "Longest span is: " << span->longestSpan() << std::endl;
		std::cout << "Shortest span is: " << span->shortestSpan() << std::endl;
		Span	span2(*span);
		delete span;
		std::cout << std::endl;
		std::cout << "Longest span is: " << span2.longestSpan() << std::endl;
		std::cout << "Shortest span is: " << span2.shortestSpan() << std::endl;
	}
	return (0);
}