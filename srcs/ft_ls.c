/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:51:17 by msorin            #+#    #+#             */
/*   Updated: 2017/11/17 13:22:52 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** for rg == 0 try opendir
** if success, ls on sub_data
** else print with (flag)
*/

static void	st_fill_struct_dir(t_doc **arg, int i, DIR *dir)
{
	struct dirent	*info;

	(void)arg;
	(void)i;
	(void)dir;
	(void)info;
}

static void st_fill_struct_file(t_doc **arg, int i, t_mask opt)
{
	if (opt & DETAIL)
	{

	}
	else
		arg[i]->to_print = ft_strdup(arg[i]->name);
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
			st_fill_struct_dir(ls->arg, i, dir_info);
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