/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:59 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/11 18:43:47 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) :
_name(name), _grade(grade)
{
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(int n)
{
	if (_grade - n > 150)
		throw (GradeTooLowException());
	else if (_grade - n < 1)
		throw (GradeTooHighException());
	else
		_grade -= n;
}

void	Bureaucrat::decrementGrade(int n)
{
	if (_grade + n > 150)
		throw (GradeTooLowException());
	else if (_grade + n < 1)
		throw (GradeTooHighException());
	else
		_grade += n;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error. Grade too high. Maximum grade is 1");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error. Grade too low. Minimum grade is 150");
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getSigned())
		return ;
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "Bureaucrat name : " << bureaucrat.getName();
	out << " , bureaucrat grade : " << bureaucrat.getGrade();
	return (out);
}
