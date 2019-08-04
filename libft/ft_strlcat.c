/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:24:08 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/09 17:34:30 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		if (dstsize > 0)
		{
			if (i + j < dstsize - 1)
				dst[i + j] = src[j];
			else if (i + j == dstsize - 1)
				dst[i + j] = '\0';
		}
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	if (i < dstsize)
		return (i + j);
	else
		return (dstsize + j);
}
