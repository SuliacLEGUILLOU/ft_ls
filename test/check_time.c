/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:49:05 by msorin            #+#    #+#             */
/*   Updated: 2017/11/02 14:57:18 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Nov  2 11:06
Jun 15 16:19
Thu Nov  2 14:57:26 2017
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_split_time(char *str)
{
	char	*ret;
	char	*t;
	int		i;

	if (!(ret = (char*)malloc(sizeof(char) * 13)))
		return (NULL);
	t = str + 4;
	i = -1;
	while (++i < 12)
		ret[i] = t[i];
	ret[12] = '\0';
	return(ret);
}

int		ft_strlen(char *s)
{
	if (!s)
		return (-1);
	if (!(*s))
		return (0);
	return (1 + ft_strlen(s + 1));
}

// void	touch_ls(size_t t)
// {

// }

int		main(void)
{
	char	*str;
	time_t	t;
	time_t	*q;
	size_t	i;

	q = malloc(sizeof(time_t));
	time(&t);
	i = (int)t;
	while (i < 253402297199)
	{
		if (!((i % 60) + ((i / 60) % 60)))
		{
			*q = i;
			str = ctime(q);
			write(1, str, ft_strlen(str));
			//write(1, "\n", 1);
			//free(str);
		}
		i++;
	}
	return (0);
}
