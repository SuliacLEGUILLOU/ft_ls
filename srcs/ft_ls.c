/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:51:17 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 18:31:00 by sle-guil         ###   ########.fr       */
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
			dir_info = opendir(ls->arg[i]->name);
			st_fill_struct_dir(ls->arg, i, dir_info);
		}
		else
		{
			ft_putendl(ls->arg[i]->name);
		}
	}
    return (ls->error);
}