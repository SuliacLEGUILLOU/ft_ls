/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:36:41 by msorin            #+#    #+#             */
/*   Updated: 2017/10/31 16:36:43 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** int		somme_opt(t_opt *opt)
** {
**	return (opt->lst + opt->rec + opt->all + opt->rev + opt->tmp);
** }
*/

static void	set_flag(t_ls *ls, char f)
{
	ls->opt->lst |= (f == 'l');
	ls->opt->rec |= (f == 'R');
	ls->opt->all |= (f == 'a');
	ls->opt->rev |= (f == 'r');
	ls->opt->tmp |= (f == 't');
}

int			is_flag(const char *arg, t_ls *ls)
{
	int		i;

	if (*arg != '-' || (*arg == '-' && !*(arg + 1)))
		return (0);
	i = 0;
	while (arg[++i])
	{
		if 
		if (arg[i] != 'l' || arg[i] != 'R' || arg[i] != 'a'
			|| arg[i] != 'r' || arg[i] != 't')
			ft_error_illegal_opt(arg[i], ls);
		else
			set_flag(ls, arg[i]);
	}
	return (1);
}
