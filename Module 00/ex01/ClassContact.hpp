/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:17:47 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/27 18:38:32 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		bool	createcontact(void);
		bool	checkcontact(void);
		void	showcontactindex(void);
		void	printcontact(void);
	
	private:

		std::string	_fname;
		std::string	_lname;
		std::string	_nick;
		std::string	_phnbr;
		std::string	_secret;

		bool	_errorcreating(int i);
};

#endif