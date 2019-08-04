/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:35:02 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/09 19:33:57 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			x;
	long long	z;

	x = 1;
	z = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
		x = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		z = z * 10 + (*str - 48);
		if (z < 0)
		{
			if (x == 1)
				return ((int)MY_LONG_MAX);
			else
				return ((int)MY_LONG_MIN);
		}
		str++;
	}
	return (z * x);
}
