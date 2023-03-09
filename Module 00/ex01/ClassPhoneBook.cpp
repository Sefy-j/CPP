/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:09:49 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/27 18:46:05 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhoneBook.hpp"

PhoneBook::PhoneBook(void) : _i(0) {}

PhoneBook::~PhoneBook(void){}

void	PhoneBook::add(void)
{
	if (_i == 8)
		_i = 0;
	if (_phbook[_i].createcontact())
		_i++;
}

void	PhoneBook::search(void)
{
	int	j;
	std::string	str;

	if (!_phbook[0].checkcontact())
	{
		std::cout << "Error. No contacts added yet"<< std::endl;
		return ;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname"<< std::endl;
	for (j = 1; j <= 8; j++)
	{
		if(_phbook[j - 1].checkcontact())
		{
			std::cout << std::setw(10) << j << "|";
			_phbook[j - 1].showcontactindex();
		}
	}
	std::cout << "Select contact index: ";
	if (!std::getline(std::cin, str))
		return ;
	if (str[0] < '1' || str[0] > '8' || str[1] != '\0' || !_phbook[str[0] - '0' - 1].checkcontact())
	{
		std::cout << "Error. Invalid index" << std::endl;
		return ;
	}
	_phbook[str[0] - '0' - 1].printcontact();
}