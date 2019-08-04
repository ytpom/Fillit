/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:45:19 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/09 23:46:34 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t res;

	res = 0;
	if (n < 0)
	{
		res++;
		n = -n;
	}
	while (n / 10)
	{
		res++;
		n = n / 10;
	}
	return (res + 1);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n / 10)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	str[--len] = n % 10 + '0';
	return (str);
}
