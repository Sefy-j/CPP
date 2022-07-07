/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 10:40:56 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSDOG_HPP
# define CLASSDOG_HPP

#include "ClassAnimal.hpp"
#include "ClassBrain.hpp"

class Dog: public Animal
{
	public:

		Dog(void);
		Dog(const Dog &other);
		~Dog(void);

		Dog	&operator=(const Dog &other);

		Brain	*getBrain(void) const;

		void	makeSound(void) const;

	private:

		Brain	*_brain;
};

#endif