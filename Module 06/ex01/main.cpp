/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:12:00 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/19 18:30:04 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

struct Data
{
	int	num;
};

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

int	main(void)
{
	Data		*dat;
	uintptr_t	raw;

	dat = new Data;
	dat->num = 2;
	std::cout << "Starting num: " << dat->num << std::endl;
	raw = serialize(dat);
	delete dat;
	dat = deserialize(raw);
	std::cout << "Ending num: " << dat->num << std::endl;
	return (0);
}
