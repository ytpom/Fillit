/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:36:01 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/11 20:36:03 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_power(int nb, int power)
{
	long long	res;
	int			x;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		if (res < 0)
			x = -1;
		else
			x = 1;
		res = res * nb;
		if (res < 0 && x == -1 && nb < 0)
			return (0);
		else if (res > 0 && x == 1 && nb < 0)
			return (0);
		else if (res < 0 && x == 1 && nb > 0)
			return (0);
		power--;
	}
	return (res);
}
