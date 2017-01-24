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
    std::cout << "_basic test + ListIsFull exception_" << std::endl;
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
        std::cout << "longest span: " << sp1.longestSpan() << std::endl;
        std::cout << "shortest span: " << sp1.shortestSpan() << std::endl;
        sp1.addNumber(540);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << std::endl << "_adding number with range of iterators_" << std::endl;
    try
    {
        Span    sp2(6);

        sp2.addNumber(2);
        sp2.addNumber(40);
        sp2.addNumber(3, 0, 5);
        sp2.print_vec();
        sp2.addNumber(6, 2, 4);
        sp2.print_vec();
        std::cout << "longest span: " << sp2.longestSpan() << std::endl;
        std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << std::endl << "_empty container_" << std::endl;
    try
    {
        Span    sp3(4);

        std::cout << "longest span: " << sp3.longestSpan() << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << std::endl << "_only one element_" << std::endl;
    try
    {
        Span    sp4(4);

        sp4.addNumber(3);
        std::cout << "shortest span: " << sp4.shortestSpan() << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << std::endl << "_big container_" << std::endl;
    try
    {
        Span    sp5(65090);

        sp5.addNumber(45, 15, 40900);
        sp5.addNumber(32, 39000, 50000);
        sp5.addNumber(500);
        sp5.addNumber(2);
        sp5.addNumber(213, 40000, 65090);
        std::cout << "longest span: " << sp5.longestSpan() << std::endl;
        std::cout << "shortest span: " << sp5.shortestSpan() << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
    return (0);
}