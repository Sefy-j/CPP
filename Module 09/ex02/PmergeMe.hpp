/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:20:57 by jlopez-f          #+#    #+#             */
/*   Updated: 2024/08/20 00:52:13 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	public:

		static int		sort(std::vector<std::string> &numbers);

	private:

		static std::vector<int>	_numbers;
		static std::vector<int>	_num_vect;
		static std::deque<int>	_num_deque;
		static std::deque<int>	_jacob_sequence;
		static int				_odd_val;
		static bool				_odd_exist;

		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);

		PmergeMe		&operator=(const PmergeMe &other);

		static bool		parsenum(std::vector<std::string> &numbers);

		static void		sortVector(void);
		static void		createSortPairsVector(std::vector<std::pair<int, int> > &pairs);
		static void		recursiveSortPairsVector(std::vector<std::pair<int, int> > &pairs, int pos);
		static void		insertPairVector(std::pair<int, int> element, std::vector<std::pair<int, int> > &pairs, int pos);
		static void		createMainSequencesVector(std::vector<std::pair<int, int> > &pairs);
		static void		insertToSortSequenceVector(std::vector<int> &tosort);
		
		static void		sortDeque(void);
		static void		createSortPairsDeque(std::deque<std::pair<int, int> > &pairs);
		static void		recursiveSortPairsDeque(std::deque<std::pair<int, int> > &pairs, int pos);
		static void		insertPairDeque(std::pair<int, int> element, std::deque<std::pair<int, int> > &pairs, int pos);
		static void		createMainSequencesDeque(std::deque<std::pair<int, int> > &pairs);
		static void		insertToSortSequenceDeque(std::deque<int> &tosort);

		static void		createJacobsthalSeq(size_t size);
		static size_t	recursiveJacobsthal(size_t jacob_index);

		static void		printVector(std::vector<int> &data);
		static void		printDeque(std::deque<int> &data);
		static bool		printError(std::string const err);
};

#endif
