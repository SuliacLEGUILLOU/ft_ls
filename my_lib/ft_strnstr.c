/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:25:03 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:49:23 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	is1;
	unsigned int	is2;
	unsigned int	count;

	if (*s2 == 0 || s2 == NULL)
		return ((char *)s1);
	is1 = 0;
	is2 = 0;
	while (s1[is1] != '\0' && is1 < n)
	{
		count = is1;
		while (s1[is1] == s2[is2] && s1[is1] != '\0' && is1 < n)
		{
			if (s2[is2 + 1] == '\0')
				return ((char *)(s1 + count));
			is1++;
			is2++;
		}
		is2 = 0;
		is1 = count + 1;
	}
	return (NULL);
}
