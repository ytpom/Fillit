/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:23:17 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/09 17:37:07 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*chr_pos;

	i = 0;
	chr_pos = NULL;
	while (s[i])
	{
		if (s[i] == ((char)c))
		{
			chr_pos = (char *)s + i;
			break ;
		}
		i++;
	}
	if (c == '\0')
		chr_pos = (char *)s + i;
	return (chr_pos);
}
