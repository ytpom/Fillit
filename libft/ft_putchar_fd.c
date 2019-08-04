/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:58:40 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/11 20:35:52 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(int c, int fd)
{
	char	tmp[4];

	if (c <= 0x7f)
		write(fd, &c, 1);
	else if (c <= 0x7ff)
	{
		tmp[0] = 0xc0 | (c >> 6);
		tmp[1] = 0x80 | (c & 0x3f);
		write(fd, tmp, 2);
	}
	else if (c <= 0xffff)
	{
		tmp[0] = 0xe0 | (c >> 12);
		tmp[1] = 0x80 | ((c >> 6) & 0x3f);
		tmp[2] = 0x80 | (c & 0x3f);
		write(fd, tmp, 3);
	}
	else if (c <= 0x10ffff)
	{
		tmp[0] = 0xf0 | (c >> 18);
		tmp[1] = 0x80 | ((c >> 12) & 0x3f);
		tmp[2] = 0x80 | ((c >> 6) & 0x3f);
		tmp[3] = 0x80 | (c & 0x3f);
		write(fd, tmp, 4);
	}
}
