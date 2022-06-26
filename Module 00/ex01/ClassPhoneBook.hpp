/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:34:29 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/26 19:50:14 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "ClassContact.hpp"

class PhoneBook
{
	public:

	Contact	phbook[8];
	int	i;

	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void);
};

#endif