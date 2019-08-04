/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:20:36 by jphilip-          #+#    #+#             */
/*   Updated: 2019/04/07 17:20:40 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tetr
{
	char			tetri[4][4];
	char			value;
	int				x;
	int				y;
	struct s_tetr	*next;
}					t_tetr;

int					read_tetri(char *src, t_tetr **start);
int					print_sol(t_tetr *tmp, int size);
int					check_tetri(t_tetr **start, char *buf);

#endif
