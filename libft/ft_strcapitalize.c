/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:35:10 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/11 20:35:12 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if ((str[i] > 96 && str[i] < 123) || (str[i] > 64 && str[i] < 91) ||
			(str[i] > 47 && str[i] < 58))
			if (flag == 0)
			{
				if (str[i] > 96 && str[i] < 123)
					str[i] = str[i] - 32;
				flag = 1;
			}
			else
			{
				if (str[i] > 64 && str[i] < 91)
					str[i] = str[i] + 32;
			}
		else
			flag = 0;
		i++;
	}
	return (str);
}
