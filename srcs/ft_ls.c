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

static void	recur_dir(t_doc **data, t_mask opt, int i);
static void	print_subdir(t_doc **data, t_mask opt);


static void st_fill_struct_file(t_doc **arg, int i, t_mask opt)
{
	if (opt & (DETAIL | COLOR | CLASSIFY))
		get_detail(arg, i, opt);
	else
		arg[i]->to_print = ft_strdup(arg[i]->name);
}

static void	recur_dir(t_doc **data, t_mask opt, int i)
{
	DIR	*d;

	if (data[i]->name[0] == '.' && !(opt & (ALL + ALL_MAJ)))
		return ;
	if (!((data[i]->stat->st_mode & S_IFDIR)
		&& !(data[i]->stat->st_mode & S_IFLNK)))
		return ;
	if (!ft_strcmp(data[i]->name, ".") || !ft_strcmp(data[i]->name, ".."))
		return ;
	d = opendir(data[i]->path);
	st_fill_struct_dir(data, i, d, opt);
	closedir(d);
	ft_putchar('\n');
	ft_putstr(data[i]->path);
	ft_putendl(":");
	print_subdir(data[i]->sub_dir, opt);
}

static void	print_subdir(t_doc **data, t_mask opt)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		if (data[i]->name[0] == '.' && !(opt & (ALL + ALL_MAJ)))
			continue ;
		if (!(opt & ALL) && !(ft_strcmp(data[i]->name, ".")
			&& ft_strcmp(data[i]->name, "..")))
			continue ;
		st_fill_struct_file(data, i, opt);
		ft_putendl(data[i]->to_print);
	}
	if (!(opt & RECUR))
		return ;
	i = -1;
	while(data[++i])
	{
		if (opt & RECUR)
			recur_dir(data, opt, i);
	}
}

// This function will have to call the detail function.
static void	st_print(t_ls const *ls)
{
	int		i;

	i = 0;
	if (ls->opt & DETAIL)
	{
		ft_putendl("Total de fichier dans le dossier");
	}
	while (ls->arg[i])
	{
		if (i && ls->arg[i]->sub_dir)
			ft_putchar('\n');
		ft_putendl(ls->arg[i]->to_print);
		if (ls->arg[i]->sub_dir)
			print_subdir(ls->arg[i]->sub_dir, ls->opt);
		i++;
	}
}

int			ft_ls(t_ls *ls)
{
	int		i;
	DIR		*dir_info;

	i = 0;
	while (ls->arg[i])
	{
		if (ls->arg[i]->err)
			ls->arg[i]->to_print = ft_strdup(ls->arg[i]->err);
		else if ((S_IFDIR & ls->arg[i]->stat->st_mode)
			&& !(S_IFLNK & ls->arg[i]->stat->st_mode))
		{
			dir_info = opendir(ls->arg[i]->path);
			st_fill_struct_dir(ls->arg, i, dir_info, ls->opt);
			closedir(dir_info);
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
