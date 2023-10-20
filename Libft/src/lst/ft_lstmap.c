/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:17:56 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 12:14:58 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;

	if (!lst)
		return (0);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (0);
	last = first;
	lst = lst->next;
	while (lst)
	{
		if (lst->content)
		{
			last->next = ft_lstnew(f(lst->content));
			lst = lst->next;
			last = last->next;
		}
		else
		{
			del(lst->content);
			free(lst);
		}
	}
	return (first);
}
