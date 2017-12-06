/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:26:02 by msorin            #+#    #+#             */
/*   Updated: 2017/12/01 11:26:05 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		need_swap(t_doc *s1, t_doc *s2, t_mask opt)
{
	if (opt & TIME)
	{
		if (s1->mtime > s2->mtime)
			return (!(opt & REVERSE));
		if (s1->mtime < s2->mtime)
			return (opt & REVERSE);
		if (s1->stat->st_atime > s2->stat->st_atime)
			return (!(opt & REVERSE));
		if (s1->stat->st_atime < s2->stat->st_atime)
			return (opt & REVERSE);
	}
	if (ft_strcmp(s1->name, s2->name) < 0 && !(opt & REVERSE))
		return (1);
	if (ft_strcmp(s1->name, s2->name) > 0 && (opt & REVERSE))
		return (1);
	return (0);
}

void	sort_indir(t_doc **data, t_mask opt)
{
	t_doc	*t;
	int		i;
	int		j;

	if (!data || !data[0] || (opt & NO_SORT))
		return ;
	i = 1;
	while (data[i])
	{
		j = 0;
		while (j < i)
		{
			if (need_swap(data[i], data[j], opt))
			{
				t = data[i];
				data[i] = data[j];
				data[j] = t;
			}
			j++;
		}
		i++;
	}
}
