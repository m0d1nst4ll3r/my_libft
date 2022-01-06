/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:50:34 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/06 18:00:02 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Note : '.5' is considered to be a valid float equivalent to '0.5'
int	ft_isfloat(const char *s)
{
	if (!s || !*s)
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (*s && *s != '.' && *s != ',')
		return (0);
	if (*s)
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s)
		return (0);
	return (1);
}
