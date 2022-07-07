/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 12:23:31 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCAT_HPP
# define CLASSCAT_HPP

#include "ClassAnimal.hpp"
#include "ClassBrain.hpp"

class Cat: public Animal
{
	public:

		Cat(void);
		Cat(const Cat &other);
		~Cat(void);

		Cat	&operator=(const Cat &other);

		Brain	*getBrain(void) const;

		void	makeSound(void) const;

	private:

		Brain	*_brain;
};

#endif