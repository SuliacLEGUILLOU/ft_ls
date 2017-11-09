/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:51:17 by msorin            #+#    #+#             */
/*   Updated: 2017/10/30 16:51:18 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int	is_flag(const char *arg)
{
	int		i;

	if (*arg != '-' || (*arg == '-' && !*(arg + 1)))
		return (0);
	i = 0;
	while (arg[++i])
	{
		if (arg[i] != 'l' || arg[i] != 'R' || arg[i] != 'a'
			|| arg[i] != 'r' || arg[i] != 't')
			ft_error_illegal_opt(arg[i]);
	}
}

static void	set_dir(char **dir, int pos, int argc, char **argv)
{
	char	*t1;
	char	*t2;
	int		i;
	int		j;

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
	t_opt	*opt;
	int		i;

	i = 0;
	init_opt(opt);
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
	return (ft_ls(dir, opt));
}
