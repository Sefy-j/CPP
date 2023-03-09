/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:29:37 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 18:26:28 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int	main(void)
{
	int	n = 17;
	int	n2 = 42;
	std::list<int>		lst;
	std::vector<int>	vec;
	std::list<int>::const_iterator		itls;
	std::vector<int>::const_iterator	itv;

	for(int i = 0; i < 20; i++)
		lst.push_back(i);
	for (int i = 20; i < 50; i++)
		vec.push_back(i);
	std::cout << "List test" << std::endl;
	try
	{
		itls = easyfind< std::list<int> >(lst, n);
		std::cout << "Number " << *itls << " found!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		try
	{
		itls = easyfind< std::list<int> >(lst, n2);
		std::cout << "Number " << *itls << " found!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Vector test" << std::endl;
	try
	{
		itv = easyfind< std::vector<int> >(vec, n);
		std::cout << "Number " << *itv << " found!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		try
	{
		itv = easyfind< std::vector<int> >(vec, n2);
		std::cout << "Number " << *itv << " found!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}