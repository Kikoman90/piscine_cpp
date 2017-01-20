/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:21:18 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/20 19:26:30 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctime>

class   Base { public: virtual ~Base() {} };

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base    *generate(void)
{
    Base    *randomBase;
    int     i;

    i = rand() % 3;
    if (i == 0)
    {
        std::cout << "_class A generated_" << std::endl;
        return (randomBase = new A());
    }
    else if (i == 1)
    {
        std::cout << "_class B generated_" << std::endl;
        return (randomBase = new B());
    }
    std::cout << "_class C generated_" << std::endl;
    return (randomBase = new C());
}

void    identify_from_pointer( Base * p )
{
    A   *cl_a = dynamic_cast<A *>(p);
    if (cl_a) { std::cout << "class A identified from pointer" << std::endl; }
    B   *cl_b = dynamic_cast<B *>(p);
    if (cl_b) { std::cout << "class B identified from pointer" << std::endl; }
    C   *cl_c = dynamic_cast<C *>(p);
    if (cl_c) { std::cout << "class C identified from pointer" << std::endl; }
}

void    identify_from_reference( Base & p )
{
    try
    {
        A   &cl_a = dynamic_cast<A &>(p);
        std::cout << "class A identified from reference" << std::endl;
        static_cast<void>(cl_a);
    }
    catch (std::bad_cast &bc) {}
    try
    {
        B   &cl_b = dynamic_cast<B &>(p);
        std::cout << "class B identified from reference" << std::endl;
        static_cast<void>(cl_b);
    }
    catch (std::bad_cast &bc) {}
    try
    {
        C   &cl_c = dynamic_cast<C &>(p);
        std::cout << "class C identified from reference" << std::endl;
        static_cast<void>(cl_c);
    }
    catch (std::bad_cast &bc) {}
}

int     main()
{
    srand(time(NULL));
    Base    *p = generate();
    identify_from_pointer(p);
    identify_from_reference(*p);
    return (0);
}