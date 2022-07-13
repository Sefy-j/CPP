/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:56:20 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/11 19:53:50 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
Form("unknown", 145, 137, "unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
Form("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
Form("ShrubberyCreationForm", 145, 137, other._target) {}
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw (NotSignedException());
	if (executor.getGrade() <= _egrade)
	{
		std::ofstream outfile (this->getTarget() + "_shrubbery");

		outfile <<	"         . . ." << std::endl <<
					"   .        .  .     ..    ." << std::endl <<
					".                   .         .  ." << std::endl <<
					"                  .              " << std::endl <<
					"                 .                .." << std::endl <<
					".              .            .              ." << std::endl <<
					".               '.,        .               . " << std::endl <<
					".                'b      *" << std::endl <<
					" .                '$    #.                .." << std::endl <<
					".    .             $:   #:               ." << std::endl <<
					" ..      .  ..     *#  @):        .   . ." << std::endl <<
					"             .    :@,@):   ,.**:'   ." << std::endl <<
					" .      .,        :@@*: ..**'      .   ." << std::endl <<
					"         '#o.    .:(@'.@*'  ." << std::endl <<
					".  .       'bq,..:,@@'   ,*      .  ." << std::endl <<
					"          ,p$q8,:@)'  .p'      ." << std::endl <<
					"  .     '  . '@@Pp@@*'    .  ." << std::endl <<
					"  .  . ..    Y7'.'     .  ." << std::endl <<
					"             :@):." << std::endl <<
					"            .:@:'." << std::endl <<
					"          .::(@:.   " << std::endl; 
		outfile.close();		
	}
	else
		throw (GradeTooLowException());
}
