/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:26:02 by msorin            #+#    #+#             */
/*   Updated: 2015/02/08 14:07:25 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	is1;
	unsigned int	is2;
	unsigned int	count;

	is1 = 0;
	is2 = 0;
	if (*s2 == 0 || s2 == NULL)
		return ((char *)s1);
	while (s1[is1] != '\0')
	{
		count = is1;
		while (s1[count] == s2[is2] && s1[count] != '\0')
		{
			if (s2[is2 + 1] == '\0')
				return ((char *)(s1 + is1));
			count++;
			is2++;
		}
		is2 = 0;
		is1++;
	}
	return (NULL);
}
