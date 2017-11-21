/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:40:52 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 11:45:00 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *src, int len)
{
	int		i;
	int		min;
	char	*dest;

	min = ft_min(ft_strlen(src), len);
	if (!(dest = ft_strnew(min)))
		return (NULL);
	i = 0;
	while (i < min)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
