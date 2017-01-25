/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:05:40 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/25 19:49:03 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int     main()
{
    MutantStack<int> mstack;

    std::cout << "_testing empty()_" << std::endl;
    std::cout << "empty: " << mstack.empty() << std::endl;
    std::cout << "_testing push()_" << std::endl;
    mstack.push(5);
    std::cout << "empty: " << mstack.empty() << std::endl;
    mstack.push(17);
    std::cout << "_testing top()_" << std::endl;
    std::cout << "top: " << mstack.top() << std::endl;

    std::cout << "_pop() and size()_" << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    std::cout << "_testing iterators_" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    std::cout << "mstack: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl << std::endl << "MutantStack top element: " << mstack.top() << std::endl << "stack top element: " << s.top() << std::endl;
    
    std::cout << "_swap(MutantStack<int> &)_" << std::endl;
    MutantStack<int> mstack2;
    mstack2.push(56);
    mstack2.push(420);
    std::cout << "mstack2: ";
    for (MutantStack<int>::const_iterator it = mstack2.begin(); it != mstack2.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << "_swaping mstack with mstack_" << std::endl;
    mstack.swap(mstack2);
    std::cout << "mstack: ";
    for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "mstack2: ";
    for (MutantStack<int>::const_iterator it = mstack2.begin(); it != mstack2.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    MutantStack<std::string> mstringstack;
    mstringstack.push(" me!");
    mstringstack.push(" it's");
    mstringstack.push("Hello");
    std::cout << "mstringstack: ";
    for (MutantStack<std::string>::const_iterator it = mstringstack.begin(); it != mstringstack.end(); ++it)
        std::cout << *it;
    std::cout << std::endl;
    return (0);
}