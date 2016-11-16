/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 03:43:22 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/02 04:58:26 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		ft_length(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (str1[i] && str2[i] &&
			(unsigned char)str1[i] == (unsigned char)str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_atoi(char *str)
{
	int		s;
	int		r;
	int		k;

	r = 0;
	s = 1;
	k = 0;
	while (str[k] >= 0 && str[k] <= 32)
		k++;
	if (str[k] == '-')
		s = -1;
	if (str[k] == '+' || str[k] == '-')
		k++;
	while (str[k] && str[k] >= '0' && str[k] <= '9')
	{
		r = r * 10 + str[k] - '0';
		k++;
	}
	return (s * r);
}
