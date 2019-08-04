/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:09:55 by jphilip-          #+#    #+#             */
/*   Updated: 2018/10/20 22:52:02 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
	{
		return (0);
	}
	while ((i <= nb) && (i < 46341))
	{
		if (i * i >= nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int			ft_find_next_prime(int nb)
{
	int	i;
	int j;

	i = 3;
	if (nb <= 2)
		return (2);
	j = ft_sqrt(nb);
	if (nb % 2 == 0)
	{
		nb = ft_find_next_prime(nb + 1);
	}
	while (i <= j)
	{
		if (nb % i == 0)
		{
			nb = ft_find_next_prime(nb + 1);
		}
		i = i + 2;
	}
	return (nb);
}
