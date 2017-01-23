/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:13:58 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/23 2 1:31:47 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int     main()
{
    try
    {
        Span    sp1(6);

        sp1.addNumber(2);
        sp1.addNumber(3);
        sp1.addNumber(4);
        sp1.addNumber(6);
        sp1.addNumber(5);
        sp1.addNumber(14);
        sp1.print_vec();
        sp1.addNumber(540);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    try
    {
        Span    sp2(6);

        sp2.addNumber(2);
        sp2.addNumber(40);
        sp2.addNumber(3, 0, 5);
        sp2.print_vec();
        sp2.addNumber(6, 2, 4);
        sp2.print_vec();
        sp2.addNumber(15);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    return (0);
}