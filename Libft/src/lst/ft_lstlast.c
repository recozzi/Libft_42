/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:24:22 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 12:14:55 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{	
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
