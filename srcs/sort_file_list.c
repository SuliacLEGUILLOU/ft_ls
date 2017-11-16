/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:45 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 13:31:56 by sle-guil         ###   ########.fr       */
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
	while ((j < i) && ls->arg[j]->err)
	{
		if (!(ls->opt & NO_SORT)
			&& (ft_strcmp(t->name, ls->arg[j]->stat->name)))
			swap_doc(ls, &t, j);
		j++;
	}
	while (j < i)
	{
		swap_doc(ls, &t, j);
		j++;
	}
	ls->arg[i] = t;
}

static void	sort_file(t_ls *ls, int i)
{
	int		j;
	t_doc	*t;

	j = -1;
	t = ls->arg[i];
	while (ls->arg[j + 1]->err)
		j++;
	while (++j < i && !(ls->arg[j]->stat->st_mode & S_IFDIR))
	{
		if (ls->opt & NO_SORT)
			continue ;
		if (!(ls->opt & TIME) && (ft_strcmp(t->name, ls->arg[j]->name) < 0))
			swap_doc(ls, &t, j);
		else if ((ls->opt & TIME)
			&& (t->stat->st_ctime < ls->arg[j]->stat->st_ctime))
			swap_doc(ls, &t, j);
	}
	while (j < i)
	{
		swap_doc(ls, &t, j);
		j++;
	}
	ls->arg[i] = t;
}

static void	sort_directory(t_ls *ls, int i)
{
	int		j;
	t_doc	*t;

	j = -1;
	t = ls->arg[i];
	while ((j + 1 < i) && (ls->arg[j + 1]->err
		|| !(ls->arg[j]->stat->st_mode & S_IFDIR)))
		j++;
	while (++j < i)
	{
		if (ls->opt & NO_SORT)
			continue ;
		if (!(ls->opt & TIME) && (ft_strcmp(t->name, ls->arg[j]->name) < 0))
			swap_doc(ls, &t, j);
		else if ((ls->opt & TIME)
			&& (t->stat->st_ctime < ls->arg[j]->stat->st_ctime))
			swap_doc(ls, &t, j);
	}
	ls->arg[i] = t;
}

void		sort_file_list(t_ls *ls)
{
	DIR		*d;
	int		i;

	i = -1;
	while (ls->arg[++i])
	{
		if (lstat(ls->arg[i]->name, ls->arg[i]->stat))
		{
			ls->error = 1;
			ls->arg[i]->err = set_error(ls, i, errno);
			insert_nonstat(ls, i);
		}
		else if (!(ls->arg[i]->stat->st_mode & S_IFDIR))
			sort_file(ls, i);
		else
			sort_directory(ls, i);
	}
}
