/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 12:31:21 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	string;
	std::string	*stringPTR;
	std::string	&stringREF = string;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::cout << "String address:                 " << &string << std::endl;
	std::cout << "String address through his ptr: " << stringPTR << std::endl;
	std::cout << "String address through his ref: " << &stringREF << std::endl;
	std::cout << "String through his ptr:         " << *stringPTR << std::endl;
	std::cout << "String through his ref:         " << stringREF << std::endl;
}