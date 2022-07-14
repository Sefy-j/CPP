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

		Form(void);
		Form(std::string const name, int sgrade, int egrade, std::string const target);
		Form(const Form &other);
		virtual ~Form(void);

		Form	&operator=(const Form &other);

		std::string	getName(void) const;
		int			getSgrade(void) const;
		int			getEgrade(void) const;
		bool		getSigned(void) const;
		std::string	getTarget(void) const;

		void			beSigned(const Bureaucrat &bur);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	protected:

		const std::string	_name;
		const int			_sgrade;
		const int			_egrade;
		bool				_signed;
		const std::string	_target;

		void	checkexec(Bureaucrat const & executor) const;

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
		class NotSignedException: public std::exception
		{
			public:

				const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
