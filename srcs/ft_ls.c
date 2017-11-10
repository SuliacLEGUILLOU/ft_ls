/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:51:17 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 12:47:52 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** for rg == 0 try opendir
** if success, ls on sub_data
** else print with (flag)
*/
static void	init_ls(t_ls *ls)
{
	return ;
}

int		ft_ls(t_ls *ls)
{
	int	i;

	if (!(*dir = ft_strdup(argv[pos])))
		ft_error_malloc();
	i = 0;
	while (++i + pos < argc)
	{
		if (!(t1 = ft_strdup(argv[pos + i])))
			ft_error_malloc();
		j = -1;
		while (++j < i)
		{
			if (ft_strcmp(t1, dir[j]) < 0)
			{
				t2 = dir[j];
				dir[j] = t1;
				t1 = t2;
			}
		}
		dir[j] = t1;
	}
}

static int	ft_ls(char **dir, t_opt *opt)
{
	char	**indir;

	return (0);
}

int			main(int argc, char **argv, char **env)
{
	char	**dir;
	t_ls	*ls;
	int		i;

	i = 0;
	init_ls(ls);
	if (argc != 1)
	{
		while ((++i < argc) && is_flag(argv[i]))
			set_flag(opt, argv[i]);
	}
	else
		i++;
	if (i == argc)
	{
		if (!(*dir = ft_getenv("PWD", env)))
			ft_error_env();
	}
	else
	{
		if (!(dir = (char**)malloc(sizeof(char*) * (argv - i))))
			ft_error_malloc();
		set_dir(dir, i, argc, argv);
	}
	return (ls->error);
}
