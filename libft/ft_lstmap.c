/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:53:58 by thfoulon          #+#    #+#             */
/*   Updated: 2018/11/27 18:56:17 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *new;

	if (lst && f)
	{
		start = f(lst);
		new = start;
		while (lst->next)
		{
			lst = lst->next;
			new->next = f(lst);
			new = new->next;
		}
		return (start);
	}
	return (0);
}
