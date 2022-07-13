/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/11 18:57:11 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bur("Bob", 1);
	Form		form("form 28B", 10, 10);
	Form		form2("form 28C", 10, 10);

	std::cout << form << std::endl;
	std::cout << form2 << std::endl;
	bur.signForm(form);
	bur.decrementGrade(10);
	bur.signForm(form2);
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;
}
