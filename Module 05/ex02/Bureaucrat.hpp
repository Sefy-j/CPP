/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/11 18:46:52 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:

		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &other);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void	incrementGrade(int n);
		void	decrementGrade(int n);
		void	signForm(Form &form);

	private:

		Bureaucrat(void);
		const std::string	_name;
		int					_grade;

		class GradeTooHighException: public std::exception
		{
			public:

				const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:

				const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif