/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCharacter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:45 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/07 13:05:33 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCHARACTER_HPP
# define CLASSCHARACTER_HPP

#include "ClassICharacter.hpp"

class Character: public ICharacter
{
	public:

		Character(void);
		Character(std::string const name);
		Character(const Character &other);
		~Character(void);

		Character	&operator=(const Character &other);

		std::string const	&getName(void) const;
		AMateria			*getMateria(int n) const;

		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);

	protected:

		std::string		_name;
		AMateria		*_inventory[4];
};

#endif
