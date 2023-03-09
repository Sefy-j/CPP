/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/04 12:31:13 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon	club("crude spiked club");
		Weapon	unknown("");
		HumanA	bob("Bob", club);
		HumanA	unknownA("", unknown);

		bob.attack();
		unknownA.attack();
		club.setType("some other type of club");
		unknown.setType("dagger");
		bob.attack();
		unknownA.attack();
	}
	std::cout << std::endl;
	{
		Weapon	club("crude spiked club");
		Weapon	unknown("");
		HumanB	jim("Jim");
		HumanB	unknownB("");

		jim.attack();
		unknownB.attack();
		jim.setWeapon(club);
		unknownB.setWeapon(unknown);
		jim.attack();
		unknownB.attack();
		club.setType("some other type of club");
		unknown.setType("dagger");
		jim.attack();
		unknownB.attack();
	}
}