/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/14 11:33:08 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	{
		Bureaucrat	bur("Bob", 146);
		ShrubberyCreationForm	form("home");

		bur.executeForm(form);
		bur.signForm(form);
		bur.incrementGrade(1);
		bur.signForm(form);
		bur.executeForm(form);
		bur.incrementGrade(12);
		bur.executeForm(form);
	}
	std::cout << std::endl;
	{
		Bureaucrat	bur("Bob", 73);
		RobotomyRequestForm	form("Jim");

		bur.executeForm(form);
		bur.signForm(form);
		bur.incrementGrade(1);
		bur.signForm(form);
		bur.executeForm(form);
		bur.incrementGrade(27);
		bur.executeForm(form);
	}
	std::cout << std::endl;
	{
		Bureaucrat	bur("Bob", 26);
		PresidentialPardonForm	form("Jim");

		bur.executeForm(form);
		bur.signForm(form);
		bur.incrementGrade(1);
		bur.signForm(form);
		bur.executeForm(form);
		bur.incrementGrade(20);
		bur.executeForm(form);
	}
}
