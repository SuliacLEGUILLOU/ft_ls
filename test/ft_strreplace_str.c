/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:14:20 by msorin            #+#    #+#             */
/*   Updated: 2017/11/15 16:14:21 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		count_char(char *str, char c)
{
	int		i;
	int		ret;

	if (!c)
		return (1);
	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == c)
			ret++;
	}
	return (ret);
}

int		count_patern(char *src, char *pat)
{
	int		ret;
	char	*t;

	if (!(*pat))
		return (1);
	ret = 0;
	t = src;
	while ((t = ft_strstr(t, pat)))
	{
		t += ft_strlen(pat);
		ret++;
	}
	return (ret);
}

char	*ft_strreplace_str(char *s, char *p, char *c, char *r)
{
	int		n;
	char	*d;

	if (!s || !r || (!p && !c))
		return (NULL);
	if (!p)
		n = count_char(s, *c)
	else
		n = count_patern(s, p);
	d = malloc(sizeof(char) * (ft_strlen(s) + n * (ft_strlen(r) - 1) + 1));
	//
}
