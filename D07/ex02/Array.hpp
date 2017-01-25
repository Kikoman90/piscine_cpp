/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:51:48 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/25 16:09:09 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

template<typename T>
class Array {
	
    private:
		T               *_array;
		unsigned int    _size;

        class           InaccessibleElementException : public std::exception {

            public:
                InaccessibleElementException() {}
                InaccessibleElementException(InaccessibleElementException const &src) { *this = src; }
                virtual ~InaccessibleElementException() throw() {}

                InaccessibleElementException    &operator=(InaccessibleElementException const &rhs)
                {
                    static_cast<void>(rhs);
                    return (*this);
                }

                char const                      *what() const throw() { return ("InaccessibleElementException"); }

        };

	public:
		Array<T>()
		{
            _size = 0;
            _array = new T;
            *_array = 0;
		}
        
		Array<T>(Array const & src)
		{
            _size = src._size;
			_array = new T[_size];
            for (unsigned int i = 0 ; i < _size ; i++)
                _array[i] = src._array[i];
		}
        
		Array<T>(unsigned int n)
		{
			_size = n;
			_array = new T[n];
		}

		~Array<T>() { delete[] _array; }

		Array<T>        &operator=(Array<T> const & rhs)
		{
            if (this != &rhs)
            {
                delete[] _array;
                _size = rhs._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = rhs._array[i];
            }
            return (*this);
		}

		unsigned int    size() const { return (_size); }

		T               &operator[](unsigned int i)
		{
            int limit = _size - 1;
            if (static_cast<int>(i) > limit)
                throw (InaccessibleElementException());
            return (_array[i]);
		}
};

#endif