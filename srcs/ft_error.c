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

char	*set_error(char *name, int err)
{
	char	*err_str;

	err_str = ft_strjoin_f("ft_ls: ", name, 0);
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
** Certes, clean_ls n'est peut-etre pas indispensable,
** mais c'est sur le principe de la guerre aux leaks.
*/

void	ft_error_malloc(t_ls *ls)
{
	write(2, "A memory allocation failed\n", 27);
	clean_ls(ls);
	exit(12);
}

void	ft_error_illegal_opt(char f, t_ls *ls)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &f, 1);
	write(2, "\nusage: ls [-Ralrt] [file ...]\n", 31);
	clean_ls(ls);
	exit(1);
}
