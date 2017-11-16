/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:51:17 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 17:54:07 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** for rg == 0 try opendir
** if success, ls on sub_data
** else print with (flag)
*/

int        ft_ls(t_ls *ls)
{
    for (int i = 0; ls->arg[i]; i++) {
        ft_putendl(ls->arg[i]->name);
	}
    return (ls->error);
}