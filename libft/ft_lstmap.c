/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:36:14 by jphilip-          #+#    #+#             */
/*   Updated: 2018/12/15 03:00:05 by jphilip-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_bzero(lst->content, lst->content_size);
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(new_lst = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	first = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new_lst->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_free_list(first);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (first);
}
