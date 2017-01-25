/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:53:41 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/25 17:02:19 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <stack>
# include <list>

template< typename T>
class   MutantStack {

    public:
        typedef typename std::list<T>::iterator          iterator;
        typedef typename std::list<T>::const_iterator    const_iterator;

        MutantStack<T>() {}

        MutantStack<T>(MutantStack<T> const &src)
        {
            _container = src._container;
        }
        
        ~MutantStack<T>() {}

        MutantStack<T>  &operator=(MutantStack<T> const &rhs)
        {
            if (this != &rhs)
                _container = rhs._container;
            return (*this);
        }

        operator        std::stack<T>()
        {
            std::stack<T>   stack;
			typename        std::list<T>::reverse_iterator		rend = _container.rend();

			for (typename std::list<T>::reverse_iterator rbegin = _container.rbegin(); rbegin != rend; ++rbegin)
                stack.push(*rbegin);
			return (stack);
        }

        T               top() const { return (_container.front()); }

        bool            empty() const { return (_container.empty()); }

        size_t          size() const { return (_container.size()); }

        void            push(T const &elem) { _container.push_front(elem); }

        void            pop() { _container.pop_front(); }
        
        void            swap(MutantStack<T> &other) { std::swap(_container, other._container); }

        iterator        begin() { return (_container.begin()); }

        const_iterator  begin() const { return (_container.begin()); }

        iterator        end() { return (_container.end()); }

        const_iterator  end() const { return (_container.end()); }

    private:
        std::list<T>  _container;

};

#endif