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

void	init_opt(t_opt *opt)
{
	opt->lst = 0;
	opt->rec = 0;
	opt->all = 0;
	opt->rev = 0;
	opt->tmp = 0;
}

int		is_flag(const char *arg)
{
	int		i;

	if (*arg != '-' || (*arg == '-' && !*(arg + 1)))
		return (0);
	i = 0;
	while (arg[++i])
	{
		if (arg[i] != 'l' || arg[i] != 'R' || arg[i] != 'a'
			|| arg[i] != 'r' || arg[i] != 't')
			ft_error_illegal_opt(arg[i]);
	}
}

void	set_flag(t_opt *opt, char *arg)
{
	int		i;

	i = 0;
	while (arg[++i])
	{
		opt->lst = (arg[i] == 'l') || opt->lst;
		opt->rec = (arg[i] == 'R') || opt->rec;
		opt->all = (arg[i] == 'a') || opt->all;
		opt->rev = (arg[i] == 'r') || opt->rev;
		opt->tmp = (arg[i] == 't') || opt->tmp;
	}
}
