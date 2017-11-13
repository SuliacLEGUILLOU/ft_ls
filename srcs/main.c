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

static char	*set_name(char *av, char *pwd)
{
	char *name;

	if (av[0] == '/')
		name = ft_strdup(av);
	else
	{
		name = ft_strjoin_f(pwd, "/", 0);
		name = ft_strjoin_f(name, av, 1);
	}
	return (name);
}

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
	if (!(data = malloc(sizeof(t_doc*) * ac - i + 1)))
		ft_error_init();
	while (i + j < ac)
	{
		data[j]->name = set_name(av[i + j], ls->pwd);
		data[j]->sub_dir = NULL;
		data[j]->data = NULL;
		data[j]->to_print = NULL;
		++j;
	}
	if (j == 0)
	{
		data[0]->name = ft_strdup(ls->pwd);
		data[0]->sub_dir = NULL;
		data[0]->data = NULL;
		data[0]->to_print = NULL;
		data[1] = NULL;
	}
	else
		data[j] = NULL;
	ls->arg = data;
}

/*
** to change with ft_get/setenv
** Because stat and lstat need the absolute path,
** we have to keep the pwd in the t_ls struct;
** TO_ADD : get_env("HOME");
*/

static void	set_current_dir(t_ls *ls, char const **env)
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
	ft_error_env();
}

/*
** TODO: comment every function in order to explain why it is complicate
*/

int			main(int argc, char **argv, char const **env)
{
	t_ls	ls;
	int		i;

	ls.opt = 0;
	ls.pwd = NULL;
	ls.home = NULL;
	ls.arg = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!is_flag(argv[i], &ls))
			break ;
	}
	set_current_dir(&ls, env);
	set_arg(&ls, argv, argc, i);
	sort_file_list(&ls);
	return (ft_ls(&ls));
}
