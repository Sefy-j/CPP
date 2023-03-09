/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 19:52:58 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap1;
	ClapTrap	clap2("Claptrappington");
	ClapTrap	clap3(clap1);

	std::cout << std::endl;
	clap1.attack("Badass");
	clap2.takeDamage(5);
	clap2.beRepaired(3);
	clap2.takeDamage(8);
	std::cout << clap2;
	std::cout << std::endl;
	return (0);
}
