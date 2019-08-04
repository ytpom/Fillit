/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:20:44 by jphilip-          #+#    #+#             */
/*   Updated: 2019/04/07 18:02:15 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_sol2(t_tetr *start, t_tetr *tetr, int x, int y)
{
	int		i;
	int		j;

	while (start->value != tetr->value)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (start->tetri[i][j] == '#')
				{
					if ((start->x + i == (tetr->x + x)) &&
						(start->y + j == (tetr->y + y)))
						return (0);
				}
		}
		start = start->next;
	}
	return (1);
}

static int	check_sol(t_tetr *start, t_tetr *tetr, int size)
{
	int		x;
	int		y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (tetr->tetri[x][y] == '#')
			{
				if ((x + tetr->x) >= size || (y + tetr->y) >= size ||
					(x + tetr->x) < 0 || (y + tetr->y) < 0)
					return (0);
				if (!check_sol2(start, tetr, x, y))
					return (0);
			}
	}
	return (1);
}

static int	brutforce(t_tetr *start, t_tetr *tetr, int size)
{
	int		x;
	int		y;

	x = -4;
	while (++x < size)
	{
		y = -4;
		while (++y < size)
		{
			tetr->x = x;
			tetr->y = y;
			if (check_sol(start, tetr, size))
			{
				if (!(tetr->next))
					return (1);
				if (brutforce(start, tetr->next, size))
					return (1);
			}
		}
	}
	return (0);
}

static void	free_lst(t_tetr *start)
{
	t_tetr	*tmp;

	while (start)
	{
		tmp = start->next;
		ft_memdel((void **)(&start));
		start = tmp;
	}
}

int			main(int argc, char **argv)
{
	t_tetr	*start;
	int		size;
	int		check;

	start = NULL;
	if (argc == 2)
	{
		if (!(read_tetri(argv[1], &start)))
		{
			ft_putendl("error");
			free_lst(start);
			return (0);
		}
		size = 1;
		check = 0;
		while (!check)
			check = brutforce(start, start, ++size);
		if (!(print_sol(start, size)))
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	free_lst(start);
}
