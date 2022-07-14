/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:56:20 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/14 12:36:44 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern(void) {}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Form	*Intern::makeForm(std::string const formname, std::string const target) const
{
	int			i;
	std::string	form[3];

	form[0] = "ShrubberyCreation";
	form[1] = "RobotomyRequest";
	form[2] = "PresidentialPardon";
	for (i = 0; i < 3; i++)
	{
		if (!form[i].compare(formname))
			break ;
	}
	switch(i)
	{
		case 0: std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
				return (new ShrubberyCreationForm(target));
		case 1: std::cout << "Intern creates RobotomyRequestForm" << std::endl;
				return (new RobotomyRequestForm(target));
		case 2: std::cout << "Intern creates PresidentialPardonForm" << std::endl;
				return (new PresidentialPardonForm(target));
		default: std::cout << "Intern could not create " << formname << " form" << std::endl;
				return (NULL);
	}
}
