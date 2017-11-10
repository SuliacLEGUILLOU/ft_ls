/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:57:38 by msorin            #+#    #+#             */
/*   Updated: 2017/11/10 08:57:41 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <unistd.h>

static void	clear_ls(t_ls *ls)
{
	if (ls)
	{
		if (ls->opt)
	}
}

void	ft_error_init(void)
{
	write(2, "An error occurred while initialising data.\n", 43);
	exit(1);
}

void	ft_error_illegal_opt(char f, t_ls *ls)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &f, 1);
	write(2, "\nusage: ls [-Ralrt] [file ...]\n", 31);
}
