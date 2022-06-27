/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/27 17:46:27 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

bool	Contact::createcontact(void)
{
	int	i;

	i = 0;
	std::cout << "Introduce first name: ";
	if (!std::getline(std::cin, fname))
		return (errorcreating(1));
	std::cout << "Introduce last name: ";
	if (!std::getline(std::cin, lname))
		return (errorcreating(2));
	std::cout << "Introduce nickname: ";
	if (!std::getline(std::cin, nick))
		return (errorcreating(3));
	std::cout << "Introduce phone number: ";
	if (!std::getline(std::cin, phnbr))
		return (errorcreating(4));
	while(phnbr[i])
	{
		if (!isdigit(phnbr[i]))
			return (errorcreating(5));
		i++;
	}
	std::cout << "Introduce darkest secret: ";
	if (!std::getline(std::cin, secret))
		return (errorcreating(6));
	return (true);
}

bool	Contact::errorcreating(int i)
{
	if (i > 0)
		fname.clear();
	if (i > 1)
		lname.clear();
	if (i > 2)
		nick.clear();
	if (i > 3)
		phnbr.clear();
	if (i == 5)
		std::cout << "Error. Phone number must contain only digits." << std::endl;
	if (i > 5)
		secret.clear();
	return (false);
}
void	Contact::showcontactindex(void)
{
	if (fname.length() > 10)
		std::cout << fname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << fname << "|";
	if (lname.length() > 10)
		std::cout << lname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << lname << "|";
	if (nick.length() > 10)
		std::cout << nick.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::setw(10) << nick << std::endl;
}

void	Contact::printcontact(void)
{
	std::cout << "First Name: " << fname << std::endl;
	std::cout << "Last Name: " << lname << std::endl;
	std::cout << "Nickname: " << nick << std::endl;
	std::cout << "Phone Number: " << phnbr << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;
}

bool	Contact::checkcontact(void)
{
	if (fname.empty())
		return (false);
	return (true);
}