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

/*
** We use un pointer to a t_doc array for easyest usage
** The functions stat and lstat need the absolute pathe of a file / folder
** so we have to keep in memory the pwd
*/

static void	set_arg(t_ls *ls, char **av, int ac, int i)
{
	int		j;
	t_doc	**data;

	j = 0;
	data = malloc(sizeof(t_doc*) * ac - i + 1);
	if (i == ac)
		data[0]->name = ft_strdup(ls->pwd);
	while (i + j < ac)
	{
		if (av[i + j][0] == '/')
			data[j]->name = ft_strdup(av[i + j]);
		else
		{
			data[j]->name = ft_strjoin_f(ls->pwd, "/", 0);
			data[j]->name = ft_strjoin_f(data[j]->name, av[i + j], 1);
		}
		++j;
	}
	data[j] = NULL;
	ls->data = data;
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
			ls->pwd = ft_strdup((*env) + 4);
			return ;
		}
		env++;
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
	set_current_dir(&ls, env);
	set_arg(&ls, argv, argc, i);
	sort_file_list(ls);
	return (ft_ls(ls));
}
