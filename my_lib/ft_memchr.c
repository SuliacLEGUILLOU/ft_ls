/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:13:12 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:38:49 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (s)
	{
		i = 0;
		tmp = (unsigned char *)s;
		while (i < n)
		{
			if (tmp[i] == (unsigned char)c)
			{
				return (&tmp[i]);
			}
			i++;
		}
	}
	return (NULL);
}
