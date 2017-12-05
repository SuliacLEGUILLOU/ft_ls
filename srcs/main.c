/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:45 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 15:58:32 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** TODO: comment every function in order to explain why it is complicate
*/

int		main(int argc, char **argv, char const **env)
{
	t_ls	ls;
	int		i;
	t_int4	len1;

	i = 0;
	ls.opt = 0;
	ls.arg = NULL;
	ls.pwd = ft_getenv("PWD=", env);
	ls.home = ft_getenv("HOME=", env);
	while (++i < argc)
	{
		if (!is_flag(argv[i], &ls))
			break ;
	}
	set_arg(&ls, argv, argc, i);
	sort_file_list(&ls);
	len1 = get_len1(ls.arg);
	return (ft_ls(&ls, len1));
}
