/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:01:45 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/06 18:05:51 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	'.5' will be considered valid and cause a return of '0.5'
//	The number returned is the best possible representation in float
//		of the number represented in the string. It may not be the exact
//		same due to floating point limitations.
float	ft_atof(const char *s)
{
	size_t		i;
	size_t		j;
	float		integer;
	float		rational;

	if (!s || !ft_isfloat(s))
		return (0);
	i = 0;
	integer = 0;
	while (ft_isdigit(s[i]))
	{
		integer = integer * 10 + s[i] - '0';
		i++;
	}
	if (s[i])
		i++;
	j = i;
	rational = 0;
	while (ft_isdigit(s[i]))
	{
		rational = rational * 10 + s[i] - '0';
		i++;
	}
	rational = rational / ft_fpow(10, i - j);
	return (integer + rational);
}
