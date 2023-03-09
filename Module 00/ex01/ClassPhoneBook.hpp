/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:34:29 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/27 18:45:21 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

#include "ClassContact.hpp"

class PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);

	private:

		Contact	_phbook[8];
		int		_i;
};

#endif