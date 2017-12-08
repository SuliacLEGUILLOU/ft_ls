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

static void	st_setup_dir(t_ls *ls, int i)
{
	DIR		*dir_info;

	if (!(dir_info = opendir(ls->arg[i]->path)))
	{
		ls->error = errno;
		ls->arg[i]->err = set_error(ls->arg[i]->path, errno);
	}
	else
	{
		fill_struct_dir(ls->arg, i, dir_info, ls->opt);
		closedir(dir_info);
	}
}

int			ft_ls(t_ls *ls, t_int4 len1)
{
	int		i;

	i = -1;
	while (ls->arg[++i])
	{
		if (ls->arg[i]->err)
			continue ;
		if ((S_IFDIR & ls->arg[i]->stat->st_mode)
			&& !(S_IFLNK & ls->arg[i]->stat->st_mode))
			st_setup_dir(ls, i);
		else
			fill_struct_file(ls->arg, i, ls->opt, len1);
	}
	print_ls(ls);
	clean_ls(ls);
	while (1)
		;
	return (ls->error);
}
