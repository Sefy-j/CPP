/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:12:39 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/11 20:15:10 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(void) :
Form("unknown", 72, 45, "unknown") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
Form("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
Form("RobotomyRequestForm", 72, 45, other._target) {}
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	random;

	if (!_signed)
		throw (NotSignedException());
	if (executor.getGrade() <= _egrade)
	{
		srand (time(NULL));
		random = rand() % 2;
		if (random == 1)
			std::cout << "Bzzzpzzpp, bzzrrp... " << this->getTarget() << 
			" has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy has been a failure u_u" << std::endl;
	}
	else
		throw (GradeTooLowException());
}
