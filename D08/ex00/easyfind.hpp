/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:35:13 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/23 13:56:47 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template<typename T>
void    easyfind(T &container, int n)
{
    typename    T::const_iterator it;
    
    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
        std::cout << "Value found!" << std::endl;
    else
        throw (std::string("Value not found in container"));
}

#endif