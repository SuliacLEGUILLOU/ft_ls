/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:57:38 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 16:08:09 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_error_init(void)
{
	write(2, "An error occurred while initialising data.\n", 43);
	exit(12);
}

void	ft_error_env(void)
{
	write(2, "Error : no file in parametter and env is unset.\n", 48);
	exit(2);
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
