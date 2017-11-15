/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:03:07 by msorin            #+#    #+#             */
/*   Updated: 2017/11/15 11:03:09 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

/*
** This function return all but the last part of a string
** or only the last part of a string. The parts are cut
** depending on the char given as a parameter.
*/

char	*ft_strsplit_last(const char *str, const char c, int f)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	i = 0;
	j = -1;
	while (str[j])
	{
		if (str[j] == c)
			i = j;
		j++;
	}
	k = f ? j - i : i;
	if (!(ret = ft_strnew((k + 1))))
		return (NULL);
	j = f ? i + 1 : 0;
	k = 0;
	while ((j < i && !f) || (str[j] && f))
	{
		ret[k] = str[j];
		j++;
		k++;
	}
	return (ret);
}
