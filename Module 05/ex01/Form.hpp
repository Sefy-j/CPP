/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:59:15 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/11 18:59:16 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

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

		void	beSigned(const Bureaucrat &bur);

	private:

		Form(void);
		const std::string	_name;
		const int			_sgrade;
		const int			_egrade;
		bool				_signed;

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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif