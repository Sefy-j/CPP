/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/10 18:02:15 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form(std::string const name, int sgrade, int egrade);
		Form(const Form &other);
		~Form(void);

		Form	&operator=(const Form &other);

		std::string	getName(void) const;
		int			getSgrade(void) const;
		int			getEgrade(void) const;
		bool		getSigned(void) const;

		void	incrementGrade(int n);
		void	decrementGrade(int n);

		void	beSigned(const Bureaucrat &bur);

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


	private:

		Form(void);
		const std::string	_name;
		const int			_sgrade;
		const int			_egrade;
		bool				_signed;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif