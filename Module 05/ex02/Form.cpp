/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:56:20 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/11 19:49:40 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("unknown form"), _sgrade(1), _egrade(1),
_signed(false), _target("unknown") {}

Form::Form(std::string const name, int sgrade, int egrade, std::string const target) :
_name(name), _sgrade(sgrade), _egrade(egrade), _signed(false), _target(target)
{
	if (_sgrade > 150 || _egrade > 150)
		throw (GradeTooLowException());
	else if (_sgrade < 1 || _egrade < 1)
		throw (GradeTooHighException());
}

Form::Form(const Form &other) : _name(other._name), _sgrade(other._sgrade),
_egrade(other._egrade), _target(other._target)
{
	*this = other;
}

Form::~Form(void) {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (_name);
}

int	Form::getSgrade(void) const
{
	return (_sgrade);
}

int	Form::getEgrade(void) const
{
	return (_egrade);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

std::string	Form::getTarget(void) const
{
	return (_target);
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

const char* Form::NotSignedException::what(void) const throw()
{
	return ("form not signed");
}

void	Form::beSigned(const Bureaucrat &bur)
{
	if (_signed)
		return ;
	if (bur.getGrade() <= _sgrade)
		_signed = true;
	else
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form name : " << form.getName();
	out << " , Form signing grade : " << form.getSgrade();
	out << " , Form exec grade : " << form.getEgrade();
	if (form.getSigned())
		out << " , Signed : yes";
	else
		out << " , Signed : no";
	return (out);
}
