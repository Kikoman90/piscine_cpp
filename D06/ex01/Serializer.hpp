/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:26:45 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/19 21:07:56 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <ctime>

typedef struct  Data
{
    int         n;
    std::string s1;
    std::string s2;
}               Data;

class           Serializer {

    public:
        Serializer();
        ~Serializer();

        void            *serialize( void );
        Data            *deserialize( void * raw );

    private:
        Serializer(Serializer const &src);

        Serializer      &operator=(Serializer const &rhs);

        std::string     _GenerateString() const;

};

#endif