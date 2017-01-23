/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:33:48 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/23 13:54:55 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int     main()
{
    std::vector<int>    v;

    v.push_back(25);
    v.push_back(103);
    v.push_back(4);
    v.push_back(56);

    try { easyfind< std::vector<int> >(v, 5); }
    catch (std::string s) { std::cout << s << std::endl; }

    std::list<int>    l;

    l.push_back(25);
    l.push_back(103);
    l.push_back(4);
    l.push_back(56);

    try { easyfind< std::list<int> >(l, 56); }
    catch (std::string s) { std::cout << s << std::endl; }
    return (0);
}