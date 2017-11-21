/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:20:55 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 14:20:58 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*zone;

	if (!(zone = (char *)malloc(size * sizeof(*zone))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		zone[i] = 0;
		i++;
	}
	return (zone);
}
