/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:34:10 by jphilip-          #+#    #+#             */
/*   Updated: 2019/04/07 17:34:20 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_string(char *buf)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (buf[++i])
	{
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
				if (((buf[i] != '.') && (buf[i] != '#')) || (buf[i++] == '\n'))
					return (0);
			if (buf[i++] != '\n')
				return (0);
		}
		if (buf[i] && (buf[i] != '\n'))
			return (0);
	}
	return (1);
}

static int		read_input(char *src, char *buf)
{
	int		size;
	int		fd;

	if ((fd = open(src, O_RDONLY)) == -1)
		return (0);
	size = read(fd, buf, 546);
	buf[size] = '\0';
	if (close(fd) == -1)
		return (0);
	if (buf[size - 2] == '\n')
		return (0);
	if (!check_string(buf))
		return (0);
	return (size);
}

int				read_tetri(char *src, t_tetr **start)
{
	int		size;
	char	*buf;

	if (!(buf = (char *)ft_strnew(545)))
		return (0);
	if (!(size = read_input(src, buf)))
	{
		ft_strdel(&buf);
		return (0);
	}
	if (!(check_tetri(start, buf)))
	{
		ft_strdel(&buf);
		return (0);
	}
	ft_strdel(&buf);
	return (1);
}
