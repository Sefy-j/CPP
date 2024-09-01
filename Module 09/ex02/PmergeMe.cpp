/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:25:41 by jlopez-f          #+#    #+#             */
/*   Updated: 2024/08/22 17:53:30 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

std::vector<int>	PmergeMe::_numbers;
std::vector<int>	PmergeMe::_num_vect;
std::deque<int>		PmergeMe::_num_deque;
std::deque<int>		PmergeMe::_jacob_sequence;
int					PmergeMe::_odd_val = 0;
bool				PmergeMe::_odd_exist = false;

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe::~PmergeMe(void) {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }

int			PmergeMe::sort(std::vector<std::string> &numbers_str)
{
	if (!parsenum(numbers_str))
		return (-1);
	sortVector();
	sortDeque();
	return (0);
}

bool		PmergeMe::parsenum(std::vector<std::string> &numbers_str)
{
	unsigned long long	num;

	_numbers.clear();
	for (std::vector<std::string>::iterator it = numbers_str.begin(); it < numbers_str.end(); it++)
	{
		if (!(*it).size())
			return (printError("bad input. Only positive integers are valid."));
		for (std::string::iterator it_str = (*it).begin(); it_str < (*it).end(); it_str++)
		{
			if (!isdigit(*it_str))
				return (printError("bad input. Only positive integers are valid."));
		}
		num = strtoul((*it).c_str(), NULL, 10);
		if (num > INT_MAX)
			return (printError("bad input. Integer value is out of bounds."));
		_numbers.push_back(num);
		if (_numbers.size() > 3000)
			return (printError("bad input. Too many values."));
	}
	return (true);
}

void		PmergeMe::sortVector(void)
{
	std::clock_t						start, end;
	std::vector<std::pair<int, int> >	pairs;

	std::cout << "Before sorting with std::vector: ";
	printVector(_numbers);
	start = std::clock();
	_num_vect = _numbers;
	if (_num_vect.size() >= 2)
	{
		createSortPairsVector(pairs);
		createMainSequencesVector(pairs);
	}
	end = std::clock();
	std::cout << "After sorting with std::vector : ";
	printVector(_num_vect);
	std::cout << "Time to process a range of " << _num_vect.size() << " elements with std::vector : ";
	std::cout << 1000.0 * (end - start) / CLOCKS_PER_SEC << " us" << std::endl;
}

void		PmergeMe::createSortPairsVector(std::vector<std::pair<int, int> > &pairs)
{
	if (_num_vect.size() % 2)
	{
		_odd_val = _num_vect.back();
		_num_vect.pop_back();
		_odd_exist = true;
	}
	pairs.reserve(_num_vect.size() / 2);
	for (std::vector<int>::iterator it = _num_vect.begin(); it != _num_vect.end(); it++)
	{
		if (*it < *(it + 1))
			pairs.push_back(std::make_pair(*it, *(++it)));
		else
			pairs.push_back(std::make_pair(*(it + 1), *(it++)));
	}
	recursiveSortPairsVector(pairs, pairs.size());
}

void		PmergeMe::recursiveSortPairsVector(std::vector<std::pair<int, int> > &pairs, int pos)
{
	if (pos <= 1)
		return ;
	recursiveSortPairsVector(pairs, pos - 1);
	insertPairVector(pairs[pos - 1], pairs, pos - 2);
}

void		PmergeMe::insertPairVector(std::pair<int, int> element, std::vector<std::pair<int, int> > &pairs, int pos)
{
	while (pos >= 0 && pairs[pos].second > element.second)
	{
		pairs[pos + 1] = pairs[pos];
		pos--;
	}
	pairs[pos + 1] = element;
}

void		PmergeMe::createMainSequencesVector(std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int>	tosort;

	_num_vect.clear();
	tosort.reserve(pairs.size());
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it < pairs.end(); it++)
	{
		_num_vect.push_back((*it).second);
		tosort.push_back((*it).first);
	}
	_num_vect.insert(_num_vect.begin(), tosort[0]);
	createJacobsthalSeq(tosort.size());
	insertToSortSequenceVector(tosort);
	if (_odd_exist)
		_num_vect.insert(lower_bound(_num_vect.begin(), _num_vect.end(), _odd_val), _odd_val);
}

void		PmergeMe::insertToSortSequenceVector(std::vector<int> &tosort)
{
	int		element;
	size_t	i, new_jacob, last_jacob, final_jacob;

	if (!tosort.size() || tosort.size() == 1)
		return ;
	i = 1;
	last_jacob = 1;
	new_jacob = 1;
	final_jacob = 0;
	while (i != final_jacob)
	{
		if (i == last_jacob && i != final_jacob)
		{
			last_jacob = new_jacob;
			if (_jacob_sequence.size())
			{
				new_jacob = _jacob_sequence[0];
				if (_jacob_sequence.size() == 1)
					final_jacob = new_jacob;
				_jacob_sequence.pop_front();
				
			}
			else
			{
				new_jacob = tosort.size();
				final_jacob = last_jacob;
			}
			i = new_jacob;
		}
		element = tosort[i - 1];
		_num_vect.insert(lower_bound(_num_vect.begin(), _num_vect.end(), element), element);
		i--;
	}
}

void		PmergeMe::sortDeque(void)
{
	std::clock_t						start, end;
	std::deque<std::pair<int, int> >	pairs;

	std::cout << "Before sorting with std::deque : ";
	printVector(_numbers);
	start = std::clock();
	_num_deque.assign(_numbers.begin(), _numbers.end());
	if (_num_deque.size() >= 2)
	{
		createSortPairsDeque(pairs);
		createMainSequencesDeque(pairs);
	}
	end = std::clock();
	std::cout << "After sorting with std::deque  : ";
	printDeque(_num_deque);
	std::cout << "Time to process a range of " << _num_deque.size() << " elements with std::deque : ";
	std::cout << 1000.0 * (end - start) / CLOCKS_PER_SEC << " us" << std::endl;
}

void		PmergeMe::createSortPairsDeque(std::deque<std::pair<int, int> > &pairs)
{
	if (_num_deque.size() % 2)
	{
		_odd_val = _num_deque.back();
		_num_deque.pop_back();
		_odd_exist = true;
	}
	for (std::deque<int>::iterator it = _num_deque.begin(); it != _num_deque.end(); it++)
	{
		if (*it < *(it + 1))
			pairs.push_back(std::make_pair(*it, *(++it)));
		else
			pairs.push_back(std::make_pair(*(it + 1), *(it++)));
	}
	recursiveSortPairsDeque(pairs, pairs.size());
}

void		PmergeMe::recursiveSortPairsDeque(std::deque<std::pair<int, int> > &pairs, int pos)
{
	if (pos <= 1)
		return ;
	recursiveSortPairsDeque(pairs, pos - 1);
	insertPairDeque(pairs[pos - 1], pairs, pos - 2);
}

void		PmergeMe::insertPairDeque(std::pair<int, int> element, std::deque<std::pair<int, int> > &pairs, int pos)
{
	while (pos >= 0 && pairs[pos].second > element.second)
	{
		pairs[pos + 1] = pairs[pos];
		pos--;
	}
	pairs[pos + 1] = element;
}

void		PmergeMe::createMainSequencesDeque(std::deque<std::pair<int, int> > &pairs)
{
	std::deque<int>	tosort;

	_num_deque.clear();
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it < pairs.end(); it++)
	{
		_num_deque.push_back((*it).second);
		tosort.push_back((*it).first);
	}
	_num_deque.insert(_num_deque.begin(), tosort[0]);
	createJacobsthalSeq(tosort.size());
	insertToSortSequenceDeque(tosort);
	if (_odd_exist)
		_num_deque.insert(lower_bound(_num_deque.begin(), _num_deque.end(), _odd_val), _odd_val);
}

void		PmergeMe::insertToSortSequenceDeque(std::deque<int> &tosort)
{
	int		element;
	size_t	i, new_jacob, last_jacob, final_jacob;

	if (!tosort.size() || tosort.size() == 1)
		return ;
	i = 1;
	last_jacob = 1;
	new_jacob = 1;
	final_jacob = 0;
	while (i != final_jacob)
	{
		if (i == last_jacob && i != final_jacob)
		{
			last_jacob = new_jacob;
			if (_jacob_sequence.size())
			{
				new_jacob = _jacob_sequence[0];
				if (_jacob_sequence.size() == 1)
					final_jacob = new_jacob;
				_jacob_sequence.pop_front();
				
			}
			else
			{
				new_jacob = tosort.size();
				final_jacob = last_jacob;
			}
			i = new_jacob;
		}
		element = tosort[i - 1];
		_num_deque.insert(lower_bound(_num_deque.begin(), _num_deque.end(), element), element);
		i--;
	}
}

void		PmergeMe::createJacobsthalSeq(size_t size)
{
	size_t	jacob_index;

	jacob_index = 3;
	_jacob_sequence.clear();
	while(recursiveJacobsthal(jacob_index) < size - 1)
	{
		_jacob_sequence.push_back(recursiveJacobsthal(jacob_index));
		jacob_index++;
	}
}

size_t		PmergeMe::recursiveJacobsthal(size_t jacob_index)
{
	if (!jacob_index)
		return (0);
	if (jacob_index == 1)
		return (1);
	return (recursiveJacobsthal(jacob_index - 1) + 2 * recursiveJacobsthal(jacob_index - 2));
}

void		PmergeMe::printVector(std::vector<int> &data)
{
	for (std::vector<int>::iterator it = data.begin(); it < data.end(); it++)
	{
		if (it != data.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

void		PmergeMe::printDeque(std::deque<int> &data)
{
	for (std::deque<int>::iterator it = data.begin(); it < data.end(); it++)
	{
		if (it != data.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

bool		PmergeMe::printError(std::string const err)
{
	std::cerr << "Error: " << err << std::endl;
	return (false);
}
