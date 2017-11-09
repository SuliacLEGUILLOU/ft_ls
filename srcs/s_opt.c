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

int		somme_opt(t_opt *opt)
{
	return (opt->lst + opt->rec + opt->all + opt->rev + opt->tmp);
}

void	init_opt(t_opt *opt)
{
	opt->lst = 0;
	opt->rec = 0;
	opt->all = 0;
	opt->rev = 0;
	opt->tmp = 0;
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
