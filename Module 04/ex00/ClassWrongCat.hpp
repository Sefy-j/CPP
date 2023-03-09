/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongCat.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/06 16:21:10 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSWRONGCAT_HPP
# define CLASSWRONGCAT_HPP

#include "ClassWrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:

		WrongCat(void);
		WrongCat(const WrongCat &other);
		~WrongCat(void);

		WrongCat	&operator=(const WrongCat &other);

		void	makeSound(void) const;
};

#endif