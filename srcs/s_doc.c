/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_doc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:56 by msorin            #+#    #+#             */
/*   Updated: 2017/11/17 13:15:29 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <unistd.h>

static char	*get_file_name(char *av, t_ls *ls)
{
	char *name;

	if (av[0] == '/')
		name = ft_strdup(av);
	else if (av[0] == '~')
		return NULL;
	else
	{
		name = ft_strjoin_f(ls->pwd, "/", 0);
		name = ft_strjoin_f(name, av, 1);
	}
	return (name);
}

t_doc	*insert_value(char *name, char *path, int flag)
{
	t_doc	*tmp;

ft_putendl("Start 1.");
	if (!(tmp = (t_doc*)malloc(sizeof(t_doc))))
		return (NULL);
ft_putendl("Start 2.");
	tmp->name = ft_strdup(name);
	tmp->path = ft_strdup(path);
	tmp->sub_dir = NULL;
	tmp->to_print = NULL;
	tmp->err = NULL;
	tmp->stat = malloc(sizeof(t_stat));
	if (lstat(path, tmp->stat))
		tmp->err = set_error(tmp->name, errno);
	if (flag & 1)
		free(name);
	if (flag & 2)
		free(path);
	return (tmp);
}

/*
** We use un pointer to a t_doc array for easyest usage
** The functions stat and lstat need the absolute path of a file / folder
** so we have to keep in memory the pwd
*/

void	set_arg(t_ls *ls, char **av, int ac, int i)
{
	int		j;
	t_doc	**data;
	char	*name;
	char	*file;
	t_doc	*tmp;

	tmp = NULL;
	j = -1;
	if (!(ls->arg = malloc(sizeof(t_doc*) * (ac - i + 1))))
		ft_error_init();
	data = ls->arg;
	while (++j + i < ac)
	{
		ft_putendl("?");
		file = get_file_name(av[j + i], ls);
		name = ft_strsplit_last(file, '/', 1);
		data[j] = insert_value(name, file, 3);
	}
	if (j == 0)
	{
		data[0] = insert_value(".", ls->pwd, 0);
		j++;
	}
	data[j] = NULL;
}
