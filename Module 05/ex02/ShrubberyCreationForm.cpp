/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:56:20 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/14 11:32:20 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
Form("ShrubberyCreationForm", 145, 137, "unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
Form("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
Form("ShrubberyCreationForm", 145, 137, other._target)
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
	checkexec(executor);
	std::cout << executor.getName() << " executes " << _name << std::endl;
	std::ofstream outfile ((this->getTarget() + "_shrubbery").c_str());
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
