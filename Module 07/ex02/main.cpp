/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:29:37 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 16:38:04 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClassArray.hpp"
#include <cstdlib>

#define MAX_VAL 10

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "My array numbers[" << i << "] = " << numbers[i];
		std::cout << ", Int array mirror[" << i << "] = " << mirror[i] << std::endl;
	}
	std::cout << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "Assignation operator array tmp[" << i << "] = " << tmp[i];
			std::cout << ", copy constructor array mirror[" << i << "] = " << mirror[i] << std::endl;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	Array<int> test(numbers);
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i];
		std::cout << ", test[" << i << "] = " << test[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i];
		std::cout << ", test[" << i << "] = " << test[i] << std::endl;
	}
	delete [] mirror;
	return 0;
}