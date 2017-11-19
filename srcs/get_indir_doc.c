/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indir_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:30:31 by msorin            #+#    #+#             */
/*   Updated: 2017/11/17 10:30:34 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <sys/stat.h>
#include <stdlib.h>

static void	st_swap_doc(t_doc **src, t_doc **d, int j)
{
	t_doc	*t;

	t = src[j];
	src[j] = *d;
	*d = t;
}

static int	st_get_lst_ln(t_tmp *s)
{
	t_tmp	*t;

	if (!s)
		return (0);
	t = s;
	while (t->next)
		t = t->next;
	return (t->nb);
}

static void	st_insert_new_doc(t_doc **arg, int i, t_doc *d, t_mask opt)
{
	int		j;
	t_doc	*t;

	j = 0;
	t = d;
	while (arg[i]->sub_dir[j])
	{
		if ((opt & TIME) && arg[i]->sub_dir[j]->ctime > d->ctime)
			st_swap_doc(arg[i]->sub_dir, &t, j);
		else if (!(opt & NO_SORT)
			&& (ft_strcmp(arg[i]->sub_dir[j]->name, d->name) > 0))
			st_swap_doc(arg[i]->sub_dir, &t, j);
		j++;
	}
	arg[i]->sub_dir[j] = t;
}

void	filling_sub_dir(t_doc **arg, int i, t_tmp *lst, t_mask opt)
{
	t_tmp	*t1;
	t_tmp	*t2;
	t_doc	*d;
	t_stat	*stat;

	arg[i]->sub_dir = malloc(sizeof(t_doc*) * (st_get_lst_ln(lst) + 1));
	arg[i]->sub_dir[0] = NULL;
	stat = malloc(sizeof(t_stat));
	t1 = lst;
	while (t1->next)
	{
		d = malloc(sizeof(t_doc));
		d->name = ft_strdup(t1->dir->d_name);
		d->path = ft_strjoin_f(arg[i]->path, t1->dir->d_name, 0);
		lstat(d->path, stat);
		d->stat = stat;
		d->ctime = stat->st_ctime;
		d->to_print = ft_strjoin_f("printing : ", d->name, 0);// to replace with aff/aff_det
		st_insert_new_doc(arg, i, d, opt);
		t2 = t1;
		t1 = t1->next;
		free(t2);
	}
}
