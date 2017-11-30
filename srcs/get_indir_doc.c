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
#include <unistd.h>

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
		if ((opt & TIME) && (arg[i]->sub_dir[j]->mtime < d->mtime))
			st_swap_doc(arg[i]->sub_dir, &t, j);
		else if (!(opt & NO_SORT)
			&& (ft_strcmp(arg[i]->sub_dir[j]->name, d->name) > 0))
			st_swap_doc(arg[i]->sub_dir, &t, j);
		j++;
	}
	arg[i]->sub_dir[j] = t;
	arg[i]->sub_dir[j + 1] = NULL;
}

static void	filling_sub_dir(t_doc **arg, int i, t_tmp *lst, t_mask opt)
{
	t_tmp	*t1;
	t_doc	*d;
	char	*name;
	char	*path;
	int		len;

	len = st_get_lst_ln(lst);
	arg[i]->sub_dir = malloc(sizeof(t_doc*) * (len + 1));
	while (--len >= 0)
		arg[i]->sub_dir[len] = NULL;
	t1 = lst;
	while (t1)
	{
		name = ft_strdup(t1->dir->d_name);
		path = ft_strdup(ft_strcmp(arg[i]->path, "/") ? arg[i]->path : "");
		path = ft_strjoin_f(path, "/", 1);
		path = ft_strjoin_f(path, name, 1);
		d = insert_value(name, path, 3, 0);
		st_insert_new_doc(arg, i, d, opt);
		t1 = t1->next;
	}
	clean_t_tmp(lst);
}

void		st_fill_struct_dir(t_doc **arg, int i, DIR *dir, t_mask opt)
{
	t_dir	*info;
	t_tmp	*t1;
	t_tmp	*t2;
	t_tmp	*t3;
	int		j;

	t1 = NULL;
	t2 = NULL;
	t3 = NULL;
	j = 1;
	while ((info = readdir(dir)))
	{
		t2 = malloc(sizeof(t_tmp));
		t2->dir = copy_dirent(info);
		t2->nb = j++;
		t2->next = NULL;
		if (!t1)
			t1 = t2;
		else
			t3->next = t2;
		t3 = t2;
	}
	arg[i]->to_print = ft_strjoin_f(arg[i]->path, ":", 0);
	filling_sub_dir(arg, i, t1, opt);
}
