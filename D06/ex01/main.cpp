/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 21:02:10 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/19 21:07:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int         main(void)
{
    Serializer  serial;
    Data        *newData;
    void        *rawData;

    rawData = serial.serialize();
    newData = serial.deserialize(rawData);
    std::cout << "Data: " << newData->s1 << "_" << newData->n << "_" << newData->s2 << std::endl;
    delete newData;
    return (0);
}