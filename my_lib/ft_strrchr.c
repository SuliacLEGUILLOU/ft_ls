/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:25:31 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:50:28 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (ft_isascii(c) == 1)
	{
		i = ft_strlen(s);
		while (i >= 0 && s[i] != c)
			i--;
		if (s[i] == c)
			return ((char *)(s + i));
		else
			return (NULL);
	}
	return (NULL);
}
