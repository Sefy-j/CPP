/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/06 16:35:35 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"
#include "ClassDog.hpp"
#include "ClassCat.hpp"
#include "ClassWrongAnimal.hpp"
#include "ClassWrongCat.hpp"

int	main(void)
{
	{
		const	Animal* meta = new Animal();
		const	Animal* i = new Cat();
		const	Animal* j = new Dog();
		
		std::cout << j->getType() << " -> Dog" << std::endl;
		std::cout << i->getType() << " -> Cat" << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	std::cout << "----------------" << std::endl;
	{
		const	WrongAnimal* meta = new WrongAnimal();
		const	WrongAnimal* wrong = new WrongCat();
		
		std::cout << wrong->getType() << " -> WrongCat" << std::endl;
		meta->makeSound();
		wrong->makeSound();
		delete meta;
		delete wrong;
	}
}
