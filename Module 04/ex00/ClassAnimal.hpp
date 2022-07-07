/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/06 15:58:58 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSANIMAL_HPP
# define CLASSANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:

		Animal(void);
		Animal(std::string const type);
		Animal(const Animal &other);
		virtual	~Animal(void);

		Animal	&operator=(const Animal &other);

		const std::string	getType(void) const;

		virtual void	makeSound(void) const;

	protected:

		std::string		_type;
};

#endif