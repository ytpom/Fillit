/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:26:24 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/14 22:27:49 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_arr(char **arr, int i)
{
	while (i)
		free(arr[--i]);
	free(arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	if (!(arr = (char **)malloc(sizeof(*arr) * (len + 1))))
		return (NULL);
	while (len--)
	{
		while (*s && *s == c)
			s++;
		if (!(arr[i] = ft_strsub(s, 0, ft_word_len(s, c))))
		{
			ft_free_arr(arr, i);
			return (NULL);
		}
		s = s + ft_word_len(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
