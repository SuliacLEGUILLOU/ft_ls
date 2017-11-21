/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 15:35:29 by msorin            #+#    #+#             */
/*   Updated: 2015/02/20 15:55:49 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	tmp = NULL;
	if (!lst)
		return (NULL);
	if (lst->next)
	{
		tmp = ft_lstmap(lst->next, f);
		if (!tmp)
			return (NULL);
	}
	res = f(lst);
	if (!res)
		return (NULL);
	res->next = tmp;
	return (res);
}
