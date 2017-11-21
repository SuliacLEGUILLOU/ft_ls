/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:28:58 by msorin            #+#    #+#             */
/*   Updated: 2015/02/06 16:55:54 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_checkws(char c)
{
	return ((c == '\t' || c == '\n' || c == ' ') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	start;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	size = (ft_strlen(s));
	start = 0;
	j = 1;
	while (s[start] == '\t' || s[start] == ' ' || s[start] == '\n')
		start++;
	while ((size - j) >= start && ft_checkws(s[size - j]))
		j++;
	str = ft_strsub(s, start, size - j - start + 1);
	if (!str)
		return (NULL);
	else
		return (str);
}
