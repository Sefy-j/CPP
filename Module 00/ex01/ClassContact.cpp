/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/27 18:43:28 by jlopez-f         ###   ########.fr       */
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
	if (!std::getline(std::cin, _fname) || _fname.empty())
		return (_errorcreating(1));
	std::cout << "Introduce last name: ";
	if (!std::getline(std::cin, _lname))
		return (_errorcreating(2));
	std::cout << "Introduce nickname: ";
	if (!std::getline(std::cin, _nick))
		return (_errorcreating(3));
	std::cout << "Introduce phone number: ";
	if (!std::getline(std::cin, _phnbr) || _phnbr.empty())
		return (_errorcreating(4));
	while(_phnbr[i])
	{
		if (!isdigit(_phnbr[i]))
			return (_errorcreating(5));
		i++;
	}
	std::cout << "Introduce darkest secret: ";
	if (!std::getline(std::cin, _secret))
		return (_errorcreating(6));
	return (true);
}

bool	Contact::_errorcreating(int i)
{
	if (i > 0)
		_fname.clear();
	if (i > 1)
		_lname.clear();
	if (i > 2)
		_nick.clear();
	if (i > 3)
		_phnbr.clear();
	if (i == 5)
		std::cout << "Error. Phone number must contain only digits." << std::endl;
	if (i > 5)
		_secret.clear();
	if (i != 5)
		std::cout << "Error creating contact." << std::endl;
	return (false);
}
void	Contact::showcontactindex(void)
{
	if (_fname.length() > 10)
		std::cout << _fname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << _fname << "|";
	if (_lname.length() > 10)
		std::cout << _lname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << _lname << "|";
	if (_nick.length() > 10)
		std::cout << _nick.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::setw(10) << _nick << std::endl;
}

void	Contact::printcontact(void)
{
	std::cout << "First Name: " << _fname << std::endl;
	std::cout << "Last Name: " << _lname << std::endl;
	std::cout << "Nickname: " << _nick << std::endl;
	std::cout << "Phone Number: " << _phnbr << std::endl;
	std::cout << "Darkest Secret: " << _secret << std::endl;
}

bool	Contact::checkcontact(void)
{
	if (_fname.empty())
		return (false);
	return (true);
}