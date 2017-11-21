/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:15:49 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:40:11 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*size;

	size = (unsigned char *)malloc(sizeof(*size) * n);
	ft_memcpy(size, s2, n);
	ft_memcpy(s1, size, n);
	return (s1);
}
