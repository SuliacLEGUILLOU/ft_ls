/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:20:42 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:44:44 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	count = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size < i)
		return (size + j);
	while (src[count] != '\0' && count + i < size - 1)
	{
		dst[i + count] = src[count];
		count++;
	}
	dst[i + count] = '\0';
	return (i + j);
}
