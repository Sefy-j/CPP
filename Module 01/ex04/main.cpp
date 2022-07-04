/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:37:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/30 19:59:58 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	ft_error(int error)
{
	if (error == 1)
	{
		std::cout << "Error. Wrong number of arguments" << std::endl;
		return (1);
	}
	if (error == 2)
	{
		std::cout << "Error. Empty replace string" << std::endl;
		return (1);
	}
	if (error == 3)
	{
		std::cout << "Error. Invalid file" << std::endl;
		return (1);
	}
	return (1);
}

void	ft_replace(std::ifstream &file, std::ofstream &frepl, std::string strfind ,std::string strrepl)
{
	std::string	read;
	std::size_t	pos;

	while (std::getline(file, read))
	{
		pos = read.find(strfind);
		while (pos != std::string::npos)
		{
			read.erase(pos, strfind.length());
			read.insert(pos, strrepl);
			pos = read.find(strfind, pos + 1);
		}
		frepl << read << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::ifstream	file;
	std::ofstream	frepl;
	std::string		fname;
	std::string		fnamerepl;
	std::string		str;
	std::string		strrepl;

	if (argc !=4)
		return (ft_error(1));
	fname = argv[1];
	fnamerepl = fname + ".replace";
	str = argv[2];
	strrepl = argv[3];
	if (str.empty() || strrepl.empty())
		return (ft_error(2));
	file.open(fname.c_str());
	frepl.open(fnamerepl.c_str());
	if (!file.is_open() || !frepl.is_open())
		return (ft_error(3));
	ft_replace(file, frepl, str, strrepl);
	file.close();
	frepl.close();
	return (0);
	
}