/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_doc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:56 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 13:46:37 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

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
	t_doc	*data;
	t_stat	*s;

	(void)s;
	if ((data = malloc(sizeof(t_doc))))
		return (NULL);
	data->name = ft_strdup(name);
	data->path = ft_strdup(path);
	data->sub_dir = NULL;
	data->to_print = NULL;
	data->err = NULL;
	data->stat = malloc(sizeof(t_stat));
	if (lstat(path, data->stat))
		data->err = set_error(data->name, errno);
	if (flag & 1)
		free(name);
	if (flag & 2)
		free(path);
	return (data);
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

	j = -1;
	if (!(data = malloc(sizeof(t_doc*) * ac - i + 1)))
		ft_error_init();
	while (++j + i < ac)
	{
		file = get_file_name(av[j + i], ls);
		name = ft_strsplit_last(file, '/', 0);
		data[j] = insert_value(name, file, 3);
	}
	if (j == 0)
	{
		data[0] = insert_value(".", ls->pwd, 0);
		j++;
	}
	data[j] = NULL;
	ls->arg = data;
}
