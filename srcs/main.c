/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:45 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 20:56:55 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	set_arg(t_ls *ls, char **av, int ac, int i)
{
	int		j;

	j = 0;
	ls->data = malloc(sizeof(t_doc) * ac - i + 1);
	while (i + j < ac)
	{
		ls->data[j].name = ft_strdup(av[i + j]);
		++j;
	}
	ls->data[j].name = NULL;
	sort_file_list(ls);
}

/*
** to change with ft_get/setenv
*/

static void set_current_dir(t_ls *ls, char const **env)
{
	while (*env)
	{
		if (!ft_strncmp(*env, "PWD=", 4))
		{
			ls->data = malloc(sizeof(t_doc) * 2);
			ls->data[0].name = ft_strdup((*env) + 4);
			ls->data[1].name = NULL;
			return ;
		}
		++env;
	}
	ft_putendl("Error : no file in parametter and env is unset");
	exit(2);
}

/*
** TODO: comment every function in order to explain why it is complicate
*/

int			main(int argc, char **argv, char const **env)
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
		set_current_dir(&ls, env);
	else
		set_arg(&ls, argv, argc, i);
	return (ft_ls(ls));
}
