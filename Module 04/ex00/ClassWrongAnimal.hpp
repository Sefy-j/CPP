/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongWrongAnimal.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/06 16:17:57 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSWRONGWrongAnimal_HPP
# define CLASSWRONGWrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:

		WrongAnimal(void);
		WrongAnimal(std::string const type);
		WrongAnimal(const WrongAnimal &other);
		virtual	~WrongAnimal(void);

		WrongAnimal	&operator=(const WrongAnimal &other);

		const std::string	getType(void) const;

		virtual void	makeSound(void) const;

	protected:

		std::string		_type;
};

#endif
