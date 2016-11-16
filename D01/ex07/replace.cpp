/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:28:15 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/09 18:09:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void    replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream       inf(filename);
    std::ofstream       outf(filename + ".replace");
    std::stringstream   read;
    std::string         s;
    size_t              pos;

    read << inf.rdbuf();
    s = read.str();
    while (true)
    {
        pos = s.find(s1);
        if (pos != std::string::npos)
            s.replace(pos, s1.length(), s2);
        else
            break;
    }
    outf << s;
	inf.close();
	outf.close();
}

int     main(int argc, char **argv)
{
    if (argc != 4)
       std::cout << "usage: ./replace 'filename' 'StringToReplace' 'StringToReplaceWith'" << std::endl;
    else
        replace(argv[1], argv[2], argv[3]);
    return (0);
}
