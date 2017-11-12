/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:52 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 16:16:53 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** for rg == 0 try opendir
** if success, ls on sub_data
** else print with (flag)
*/

int	ft_ls(t_ls *ls, int	rg)
{
	if (rg == 0)
		;
	for (int i = 0; ls->arg[i]->name; ++i) {
		ft_putendl(ls->arg[i]->name);
	}
	return (0);
}
