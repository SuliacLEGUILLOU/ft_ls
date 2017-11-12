/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:45 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 16:06:23 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	swap_doc(t_ls *ls, t_doc **d, int j)
{
	t_doc	*t;

	t = ls->arg[j];
	ls->arg[j] = *d;
	*d = t;
}

static void	insert_nonstat(t_ls *ls, int i)
{
	int		j;
	t_doc	*t;

	j = 0;
	t = ls->arg[i];
	while ((j < i) && !ls->arg[j]->stat)
	{
		if (!(ls->opt & NO_SORT) && (ft_strcmp(t, ls->arg[j]->stat)))
			swap_doc(ls, &t, j);
		j++;
	}
	while (j < i)
	{
		swap_doc(ls, &t, j);
		j++
	}
	ls->arg[j] = t;
}

static void	sort_file(t_ls *ls, int i)
{
	int	j;
	t_doc	*t;

	j = -1;
	t = ls->arg[i];
	while (!ls->arg[j + 1]->stat)
		j++;
	while (++j < i)
	{
		if (!(ls->opt & TIME) && (ft_strcmp(t->name, ls->arg[j]->name) < 0))
			swap_doc(ls, &t, j);
		else if ((ls->opt & TIME)
			&& (t->stat->st_ctime < ls->arg[j]->stat->st_ctime))
			swap_doc(ls, &t, j);
	}
	ls->arg[i] = t;
}

void	sort_file_list(t_ls *ls)
{
	DIR		*d;
	int		i;

	i = -1;
	while (ls->arg[++i])
	{
		if (lstat(ls->arg[i]->name, ls->arg[i]->stat))
		{
			ls->error = 1;
			insert_nonstat(ls, i);
		}
		if (!(d = opendir(ls->arg[i]->name)))
			sort_file(ls, i)
		else
		{
			sort_directory(ls, i);
			closedir(d);
		}
	}
}
