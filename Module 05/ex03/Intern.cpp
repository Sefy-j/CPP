/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:56:20 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/19 15:22:44 by jlopez-f         ###   ########.fr       */
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

Form	*newShrubbery(std::string const target)
{
	(void)target;
	return (NULL);
}

Form	*Intern::makeForm(std::string const formname, std::string const target) const
{
	int			i;
	std::string	form[3];
	Form		*(*ptrf[3])(std::string const);

	form[0] = "ShrubberyCreation";
	form[1] = "RobotomyRequest";
	form[2] = "PresidentialPardon";
	ptrf[0] = &ShrubberyCreationForm::newShrubbery;
	ptrf[1] = &RobotomyRequestForm::newRobotomy;
	ptrf[2] = &PresidentialPardonForm::newPresidential;
	for (i = 0; i < 3; i++)
	{
		if (!form[i].compare(formname))
		{
			std::cout << "Intern creates " << form[i] << "Form" << std::endl;
			return (ptrf[i](target));
		}
	}
	std::cout << "Intern could not create " << formname << " form" << std::endl;
	return (NULL);
}
