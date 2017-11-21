/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:30:26 by msorin            #+#    #+#             */
/*   Updated: 2015/02/20 15:54:38 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlst;

	nlst = (t_list *)malloc(sizeof(t_list));
	if (!nlst)
		return (NULL);
	if (content == NULL)
	{
		nlst->content = NULL;
		nlst->content_size = 0;
	}
	else
	{
		nlst->content = (void *)ft_memalloc(content_size);
		if (nlst->content == NULL)
		{
			free(nlst);
			return (NULL);
		}
		nlst->content = ft_memcpy(nlst->content, content, content_size);
		nlst->content_size = content_size;
	}
	nlst->next = NULL;
	return (nlst);
}
