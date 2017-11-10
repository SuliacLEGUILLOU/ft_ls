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
#include <stdlib.h>

void	set_flag(t_ls *ls, char f)
{
	t_opt	*opt;

	opt = NULL;
	if (!ls->opt)
	{
		if (!(opt = (t_opt*)malloc(sizeof(t_opt))))
			ft_error_malloc(ls);
		opt->lst = 0;
		opt->rec = 0;
		opt->all = 0;
		opt->rev = 0;
		opt->tmp = 0;		
	}
	else
		opt = ls->opt;
	opt->lst |= (f == 'l');
	opt->rec |= (f == 'R');
	opt->all |= (f == 'a');
	opt->rev |= (f == 'r');
	opt->tmp |= (f == 't');
	opt->opt = (opt->tmp + (opt->rev << 1) + (opt->all << 2)
		+ (opt->rec <<) 3 + (opt->lst << 4));
	ls->opt = opt;
}

int		is_flag(const char *arg, t_ls *ls)
{
	int		i;

	if (arg[0] != '-' || (arg[0] == '-' && !arg[1]))
		return (0);
	i = 0;
	while (arg[++i])
	{
		if (arg[i] != 'l' || arg[i] != 'R' || arg[i] != 'a'
			|| arg[i] != 'r' || arg[i] != 't')
			ft_error_illegal_opt(arg[i], ls);
		else
			set_flag(ls, arg[i]);
	}
	return (1);
}
