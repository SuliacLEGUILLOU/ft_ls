/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 15:21:20 by msorin            #+#    #+#             */
/*   Updated: 2015/02/20 15:50:57 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *d, size_t s)
{
	free(d);
	(void)s;
}

t_list		*ft_lstcpy(t_list *lst)
{
	t_list	*ret;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew(lst->content, lst->content_size);
	if (!tmp)
		return (NULL);
	ret = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(lst->content, lst->content_size);
		if (!tmp->next)
		{
			ft_lstdel(&ret, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	if (tmp->next != NULL)
		tmp->next = NULL;
	return (ret);
}
