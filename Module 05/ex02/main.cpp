/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/13 18:07:24 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	bur("Bob", 135);
	PresidentialPardonForm	form1("Jim");
	RobotomyRequestForm		form2("Jim");
	ShrubberyCreationForm	form3("home");

	bur.signForm(form1);
	bur.signForm(form2);
	bur.signForm(form3);
	bur.executeForm(form1);
	bur.executeForm(form2);
	bur.executeForm(form3);
}
