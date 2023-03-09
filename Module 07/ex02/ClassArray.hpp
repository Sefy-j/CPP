/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassArray.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:25:55 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/07/20 16:04:00 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSARRAY_HPP
# define CLASSARRAY_HPP

template <typename T>
class Array
{
	public:

		Array(void) : _array(), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array &other) : _array() { *this = other; }
		~Array(void) { delete [] _array; }

		Array	&operator=(const Array &other)
		{
			if (this != &other)
			{
				T	*temp;

				temp = new T[other._size];
				for (unsigned int i = 0; i < other._size; i++)
					temp[i] = other._array[i];
				delete [] _array;
				_array = temp;
				_size = other._size;
			}
			return (*this);
		}
		T	&operator[](const unsigned int n)
		{
			if (n >= _size)
				throw (std::out_of_range("out of range"));
			else
				return (_array[n]);
		}

		int	size(void) const { return (_size); }

	private:

		T				*_array;
		unsigned int	_size;
};

#endif