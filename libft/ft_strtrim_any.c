/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:36:23 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/11 20:36:30 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_any(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == c)
		s++;
	if (*s == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s) - 1;
	while (s[len] == c)
		len--;
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
