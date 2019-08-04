/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:23:35 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/12 21:15:57 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src < dst)
		while ((int)--len >= 0)
			*((char *)dst + len) = *((char *)src + len);
	if (src > dst)
		while (++i < len)
			*((char *)dst + i) = *((char *)src + i);
	return (dst);
}
