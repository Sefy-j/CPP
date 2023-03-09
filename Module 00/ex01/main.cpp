/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/27 17:37:35 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhoneBook.hpp"

int main()
{
	PhoneBook Phone;
	std::string	str;

	std::cout << "Select ADD, SEARCH or EXIT: ";
	while(std::getline(std::cin, str) && str.compare("EXIT"))
	{
		if (!str.compare("ADD"))
			Phone.add();
		else if (!str.compare("SEARCH"))
			Phone.search();
		else
			std::cout << "Invalid command" << std::endl;
		if (!std::cin.eof())
			std::cout << std::endl << "Select ADD, SEARCH or EXIT: ";
	}
	std::cout << std::endl;
	return (0);
}