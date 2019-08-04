/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:51:50 by jphilip-          #+#    #+#             */
/*   Updated: 2019/04/07 17:53:06 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_elem(char tmp[4][4])
{
	int		i;
	int		j;
	int		link;
	int		size;

	i = -1;
	link = 0;
	size = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tmp[i][j] == '#')
			{
				size++;
				if (j < 3 && tmp[i][j + 1] == '#')
					link++;
				if (i < 3 && tmp[i + 1][j] == '#')
					link++;
			}
	}
	if ((link < 3) || (size != 4))
		return (0);
	return (1);
}

static t_tetr	*create_elem(char *buf)
{
	t_tetr	*tmp;
	int		i;
	int		j;
	int		k;

	if (!(tmp = (t_tetr *)ft_memalloc(sizeof(t_tetr))))
		return (0);
	k = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			tmp->tetri[i][j] = buf[k++];
		k++;
	}
	return (tmp);
}

static int		create_list(char *buf, t_tetr **start)
{
	int		i;
	t_tetr	*tmp;

	if (!(tmp = create_elem(buf)))
		return (0);
	tmp->value = 'A';
	*start = tmp;
	i = 0;
	while (buf[++i * 21])
	{
		if (!(tmp->next = create_elem(buf + i * 21)))
			return (0);
		tmp = tmp->next;
		tmp->value = 'A' + i;
	}
	tmp->next = NULL;
	return (1);
}

int				check_tetri(t_tetr **start, char *buf)
{
	t_tetr	*tmp;

	if (!(create_list(buf, start)))
		return (0);
	tmp = *start;
	while (tmp)
	{
		if (!check_elem(tmp->tetri))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
