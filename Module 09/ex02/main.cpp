/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:29:37 by jlopez-f          #+#    #+#             */
/*   Updated: 2024/08/21 14:08:06 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: invalid number of arguments. Input needs at least one number." << std::endl;
	}
	else
	{
		std::vector<std::string>	nums(argv + 1, argv + argc);

		return (PmergeMe::sort(nums));
	}
}