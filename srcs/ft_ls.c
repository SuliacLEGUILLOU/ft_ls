/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:51:17 by msorin            #+#    #+#             */
/*   Updated: 2017/11/17 13:46:43 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

/*
** may need to not be static
*/

static void	st_fill_struct_dir(t_doc **arg, int i, DIR *dir, t_mask opt)
{
	t_dir	*info;
	t_tmp	*t1;
	t_tmp	*t2;

	t1 = NULL;
	t2 = NULL;
	while ((info = readdir(dir)))
	{
		if (!t1)
		{
			t1 = malloc(sizeof(t_tmp));
			t2 = t1;
			t2->nb = 1;
		}
		else
		{
			t2->next = malloc(sizeof(t_tmp));
			t2->next->nb = t2->nb + 1;
			t2 = t2->next;
		}
		t2->dir = copy_dirent(info);
		t2->next = NULL;
	}
	filling_sub_dir(arg, i, t1, opt);
	closedir(dir);
}

static void st_fill_struct_file(t_doc **arg, int i, t_mask opt)
{
	if (opt & DETAIL)
	{
		// TODO
		arg[i]->to_print = ft_strjoin("Detail ", arg[i]->name);
	}
	else
		arg[i]->to_print = ft_strdup(arg[i]->name);
}

static void	print_subdir(t_doc **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		ft_putendl(data[i]->to_print);
		if (data[i]->sub_dir)
			print_subdir(data[i]->sub_dir);
		i++;
	}
}

static void	st_print(t_ls const *ls)
{
	int		i;

	i = 0;
	if (ls->opt & DETAIL)
		ft_putendl("Total de fichier dans le dossier");
	while (ls->arg[i])
	{
		ft_putendl(ls->arg[i]->to_print);
		if (ls->arg[i]->sub_dir)
			print_subdir(ls->arg[i]->sub_dir);
		i++;
	}
}

int        ft_ls(t_ls *ls)
{
	int		i;
	DIR		*dir_info;

	i = 0;
	while (ls->arg[i])
	{
		if (S_IFDIR & ls->arg[i]->stat->st_mode)
		{
			// is a dir
			dir_info = opendir(ls->arg[i]->path);
			st_fill_struct_dir(ls->arg, i, dir_info, ls->opt);
		}
		else
		{
			st_fill_struct_file(ls->arg, i, ls->opt);
		}
		++i;
	}
	st_print(ls);
    return (ls->error);
}