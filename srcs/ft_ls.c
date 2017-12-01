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
#include <stdio.h>

static void	st_fill_struct_file(t_doc **arg, int i, t_mask opt)
{
	if (opt & (DETAIL | COLOR | CLASSIFY))
		get_detail(arg, i, opt);
	else
		arg[i]->to_print = ft_strdup(arg[i]->name);
}

void		recur_dir(t_doc **data, t_mask opt, int i, t_ls *ls)
{
	DIR		*d;

	if (data[i]->name[0] == '.' && !(opt & (ALL + ALL_MAJ)))
		return ;
	if (!((data[i]->stat->st_mode & S_IFDIR)
		&& !(data[i]->stat->st_mode & S_IFLNK)))
		return ;
	if (!ft_strcmp(data[i]->name, ".") || !ft_strcmp(data[i]->name, ".."))
		return ;
	if (!(d = opendir(data[i]->path)))
	{
		perror(data[i]->path);
		ls->error = errno;
		return ;
	}
	st_fill_struct_dir(data, i, d, opt);
	closedir(d);
	ft_putchar('\n');
	ft_putendl(data[i]->to_print);
	print_subdir(data[i]->sub_dir, opt, ls);
}

void		print_subdir(t_doc **data, t_mask opt, t_ls *ls)
{
	int		i;

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
	while (data[++i])
	{
		if (opt & RECUR)
			recur_dir(data, opt, i, ls);
	}
}

static void	st_print(t_ls *ls)
{
	int		i;

	i = 0;
	while (ls->arg[i])
	{
		if (i && ls->arg[i]->sub_dir)
			ft_putchar('\n');
		if (ls->arg[i]->err)
			ft_putendl_fd(ls->arg[i]->err, 2);
		else
			ft_putendl(ls->arg[i]->to_print);
		if (ls->arg[i]->sub_dir)
			print_subdir(ls->arg[i]->sub_dir, ls->opt, ls);
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
	clean_ls(ls);
	while (1)
		;
	return (ls->error);
}
