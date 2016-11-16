/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:49:32 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/09 16:55:14 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int		main(void)
{
	Logger	logger("log.txt");

	logger.log("console", "ceci est un message sur console");
	logger.log("file", "ceci est un message a ecrire dans un fichier");
	return (0);
}
