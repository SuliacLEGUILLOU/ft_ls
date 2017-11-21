/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:24:06 by msorin            #+#    #+#             */
/*   Updated: 2015/02/08 16:17:20 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	else
	{
		if (!s2[i] && s1[i])
			ret = ((s1[i] - s2[i]) < 0) ? 1 : (s1[i] - s2[i]);
		else if (!s1[i] && s2[i])
			ret = ((s1[i] - s2[i]) > 0) ? -1 : (s1[i] - s2[i]);
		else
			ret = s1[i] - s2[i];
		return (ret);
	}
}
