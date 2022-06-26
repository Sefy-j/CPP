/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/26 19:48:53 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhoneBook.hpp"

int main()
{
	PhoneBook Phone;
	std::string	str;

	while(str.compare("EXIT"))
	{
		std::cin >> str;
		if (!str.compare("ADD"))
			Phone.add();
		else if (!str.compare("SEARCH"))
			Phone.search();
	}
}