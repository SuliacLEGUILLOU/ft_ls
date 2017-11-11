/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:45 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 16:16:40 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void set_arg(t_ls *ls, char **av, int ac, int i)
{
	int		j;

	j = 0;
	ls->data = malloc(sizeof(t_doc*) * ac - i + 1);
	while (i + j < ac)
	{
		ls->data[j].name = ft_strdup(av[i + j]);
		++j;
	}
	ls->data[j].name = NULL;
	sort_file_list(ls);
}

int			main(int argc, char **argv, char **env)
{
	t_ls	ls;
	int		i;

	ls.opt = 0;
	ls.data = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!is_flag(argv[i], &ls))
			break ;
	}
	if (i == argc)
		(void)env;
		//set_current_dir(&ls, env);
	else
		set_arg(&ls, argv, argc, i);
	ft_ls(ls);
	return (0);
}
