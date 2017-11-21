/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:18:07 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:41:04 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	size;
	unsigned int	i;

	i = 0;
	if (s2[0] == '\0')
		return (s1);
	size = ft_strlen(s1);
	while ((char)s2[i] != '\0')
	{
		s1[size] = s2[i];
		i++;
		size++;
	}
	s1[size] = '\0';
	return (s1);
}
