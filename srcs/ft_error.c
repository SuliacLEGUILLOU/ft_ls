/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:57:38 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 13:53:48 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/errno.h>

void 	clear_ls(t_ls *ls)
{
	(void)ls;
}

char	*set_error(t_ls *ls, int i, int err)
{
	char	**name;
	char	*err_str;
	int		j;

	name = ft_strsplit(ls->arg[i]->name, '/');
	j = 0;
	while (name[j + 1])
		j++;
	err_str = ft_strjoin_f("ft_ls: ", name[j], 0);
	j = -1;
	while (name[++j])
		free(name[j]);
	free(name);
	err_str = ft_strjoin_f(err_str, ": ", 1);
	err_str = ft_strjoin_f(err_str, strerror(err), 1);
	return (err_str);
}

void	ft_error_init(void)
{
	write(2, "An error occurred while initialising data.\n", 43);
	exit(12);
}

/*
** Certes, clear_ls n'est peut-etre pas indispensable,
** mais c'est sur le principe de la guerre aux leaks.
*/

void	ft_error_malloc(t_ls *ls)
{
	write(2, "A memory allocation failed\n", 27);
	clear_ls(ls);
	exit(12);
}

void	ft_error_illegal_opt(char f, t_ls *ls)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &f, 1);
	write(2, "\nusage: ls [-Ralrt] [file ...]\n", 31);
	clear_ls(ls);
	exit(1);
}
