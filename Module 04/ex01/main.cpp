/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 13:02:59 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"
#include "ClassDog.hpp"
#include "ClassCat.hpp"

int	main(void)
{
	{
		Dog	*dog = new Dog;

		std::cout << std::endl;
		dog->getBrain()->addIdeas("Eat");
		dog->getBrain()->addIdeas("Drink");
		dog->getBrain()->printIdeas();
		Dog	*dog2 = new Dog(*dog);
		delete dog;
		dog2->getBrain()->printIdeas();
		delete dog2;
	}
	std::cout << std::endl;
	{
		int		N = 6;
		Animal	*animals[N];
		int		i;

		for (i = 0; i < N/2; i++)
			animals[i] = new Dog;
		std::cout << std::endl;
		for (i = N/2; i < N; i++)
			animals[i] = new Cat;
		std::cout << std::endl;
		for (i = 0; i < N/2; i++)
			delete animals[i];
		std::cout << std::endl;
		for (i = N/2; i < N; i++)
			delete animals[i];
	}
}
