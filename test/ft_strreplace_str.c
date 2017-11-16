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

int		count_replace(char *str, char *pat, char c)
{
	int		i;
	int		ret;
	char	*t1;
	char	*t2;

	i = 0;
	ret = 0;
	t1 = str;
	while (t1[i])
	{
		if ((t2 = ft_strnstr(str, pat, ft_strlen(pat))))
		{
			ret++;
			i += ft_strlen(pat) - 1;
		}
		else if (t1[i] == c)
			ret++;
		i++;
	}
	return (ret);
}

void	fill_tab(char ***tmp, char *str, char *pat, char c)
{
	int		i;
	int		j;
	char	*t1;
	char	*t2;

	i = -1;
	j = 0;
	t1 = str;
	t2 = NULL;
	while (t1[++i])
	{
		if ((t2 = ft_strnstr(str, pat, ft_strlen(pat))) || t1[i] == c)
		{
			(*tmp)[j] = ft_strndup(t1, i);
			if (t2)
				t1 += i + ft_strlen(pat);
			else
				t1 += i + 1;
			t2 = NULL;
			i = -1;
			j++;
		}
	}
	(*tmp)[j] = ft_strdup(t1);
	(*tmp)[j + 1] = NULL;
}

char	*ft_strjoin_tab(char ***tab, char *rep)
{
	int		i;
	char	*str;

	str = ft_strdup((*tab)[0]);
	free((*tab)[0]);
	i = 1;
	while ((*tab)[i])
	{
		str = ft_strjoin_f(str, rep, 1);
		str = ft_strjoin_f(str, (*tab)[i], 3);
		i++;
	}
	free(*tab);
	return (str);
}

char	*ft_strreplace_str(char *str, char *pat, char *c, char *rep)
{
	int		n;
	char	*dest;
	char	**tmp;

	if (!str || !rep || (!pat && !c))
		return (NULL);
	n = count_replace(str, pat, *c);
	tmp = (char**)malloc(sizeof(char*) * (n + 2));
	fill_tab(&tmp, str, pat, *c);
	dest = ft_strjoin_tab(&tmp, rep);
	return (dest);
}
