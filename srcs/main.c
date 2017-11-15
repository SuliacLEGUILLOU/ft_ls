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
