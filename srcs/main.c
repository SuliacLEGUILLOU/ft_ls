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

	if (!(ls = (t_ls*)malloc(sizeof(t_ls))))
		ft_error_init();
	ls->data = NULL;
	ls->opt = NULL;
	set_flag(ls, nul);
}

static void	set_arg(t_ls *ls, char **av, int at, int ac)
{
	return ;
}

static void	ft_setenv(t_ls *ls, char **env)
{
	char	**fold;

	*fold = ft_getenv("PWD", env);
	set_arg(ls, fold, 0, 1);
	free(*fold);
}

void		clear_ls(t_ls *ls)
{
	if (ls)
	{
		if (ls->opt)
			free(ls->opt);
		if (ls->data)
		{
			clear_data(ls->data);
			free(ls->data);
		}
		ls->opt = NULL;
		ls->data = NULL;
		free(ls);
	}
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
