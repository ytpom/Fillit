/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:38:29 by jphilip-          #+#    #+#             */
/*   Updated: 2019/04/07 17:38:40 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_string(char *map)
{
	ft_putendl(map);
	ft_strdel(&map);
}

static char	**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)ft_memalloc(sizeof(*map) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		if (!(map[i] = ft_strnew(size)))
			return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	return (map);
}

int			print_sol(t_tetr *tmp, int size)
{
	int		i;
	int		j;
	char	**map;

	if (!(map = create_map(size)))
		return (0);
	while (tmp)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (tmp->tetri[i][j] == '#')
					map[tmp->x + i][tmp->y + j] = tmp->value;
		}
		tmp = tmp->next;
	}
	i = -1;
	while (++i < size)
		print_string(map[i]);
	ft_memdel((void **)&map);
	return (1);
}
