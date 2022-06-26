/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:26:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/26 21:51:49 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

void	Contact::createcontact(void)
{
	if (this->i == 8)
		this->i = 0;
	std::cout << "First Name:";
	std::cin >> this->phbook[this->i].fname;
	std::cout << "Last Name:";
	std::cin >> this->phbook[this->i].lname;
	std::cout << "Nickname:";
	std::cin >> this->phbook[this->i].nick;
	std::cout << "Phone Number:";
	std::cin >> this->phbook[this->i].phnbr;
	std::cout << "Darkest Secret:";
	std::cin >> this->phbook[this->i].secret;
	this->i++;
}

void	PhoneBook::printcontact(void)
{
	int	j;

	j = 0;
	std::cout << "Index First Name Last Name Nickname"<< std::endl;
	while (j < this->i)
	{
		std::cout << j <<  this->phbook[j].fname << this->phbook[j].lname << this->phbook[j].nick << std::endl;
		j++;
	}
	std::cout << "Select contact index:";
	std::cin >> j;
	std::cout << "First Name:";
	std::cout << this->phbook[j].fname;
	std::cout << "Last Name:";
	std::cout << this->phbook[j].lname;
	std::cout << "Nickname:";
	std::cout << this->phbook[j].nick;
	std::cout << "Phone Number:";
	std::cout << this->phbook[j].phnbr;
	std::cout << "Darkest Secret:";
	std::cout << this->phbook[j].secret;
}