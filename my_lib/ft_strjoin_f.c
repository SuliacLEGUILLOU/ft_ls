/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:13:43 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 16:14:09 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void		ft_fill_strjoin(char *dest, char *src, size_t *i, size_t *j)
{
	if (src)
	{
		while (src[*j] != '\0')
		{
			dest[*i] = src[*j];
			*i = *i + 1;
			*j = *j + 1;
		}
	}
}

char			*ft_strjoin_f(char *s1, char *s2, int f)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	j = 0;
	ft_fill_strjoin(str, (char *)s1, &i, &j);
	j = 0;
	ft_fill_strjoin(str, (char *)s2, &i, &j);
	str[i] = '\0';
	if (f & 1)
		free(s1);
	if (f & 2)
		free(s2);
	return (str);
}
