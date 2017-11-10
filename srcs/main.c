/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:45 by msorin            #+#    #+#             */
/*   Updated: 2017/11/10 08:51:47 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	init_ls(t_ls *ls)
{
	t_opt	opt;

	if (!(ls = (t_ls*)malloc(sizeof(t_ls))))
		ft_error_init();
	ls->data = NULL;
	opt = {.lst = 0, .rec = 0, .all = 0, .rev = 0, .tmp = 0};
	ls->opt = &opt;
}

int			main(int argc, char **argv, char **env)
{
	t_ls	*ls;
	int		i;

	ls = NULL;
	init_ls(ls);
	i = 0;
	while (++i < argc)
	{
		if (!is_flag(argv[i], ls))
			break ;
	}
	if (i == argc)
		ft_setenv(ls, env);
	else
		set_arg(ls, argv, i, argc);
	return (ft_ls(ls));
}
