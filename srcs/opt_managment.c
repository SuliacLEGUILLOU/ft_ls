/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:36:41 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 15:18:06 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** ls -f enable the 'a' flag
*/

void	set_flag(t_ls *ls, char f)
{
	if (f == 'l' && !(ls->opt & DETAIL))
		ls->opt += DETAIL;
	else if (f == 'R' && !(ls->opt & RECUR))
		ls->opt += RECUR;
	else if (f == 'a' && !(ls->opt & ALL))
		ls->opt += ALL;
	else if (f == 'A' && !(ls->opt & ALL_MAJ))
		ls->opt += ALL_MAJ;
	else if (f == 'r' && !(ls->opt & REVERSE))
		ls->opt += REVERSE;
	else if (f == 't' && !(ls->opt & TIME))
		ls->opt += TIME;
	else if (f == 'f' && !(ls->opt & NO_SORT))
		ls->opt += NO_SORT + ALL;
	else if (f == 'F' && !(ls->opt & CLASSIFY))
		ls->opt += CLASSIFY;
}

int		is_flag(const char *arg, t_ls *ls)
{
	int		i;

	if (arg[0] != '-' || (arg[0] == '-' && !arg[1]))
		return (0);
	i = 0;
	while (arg[++i])
	{
		if (ft_strchr("lRaArtfF", arg[i]))
			set_flag(ls, arg[i]);
		else
			ft_error_illegal_opt(arg[i], ls);
	}
	return (1);
}
