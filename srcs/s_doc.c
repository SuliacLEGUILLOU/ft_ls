/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_doc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:56 by msorin            #+#    #+#             */
/*   Updated: 2017/11/15 10:35:57 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

static char	*get_file_name(char *av, char *pwd)
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

t_doc	*insert_value(char *path, char *name, int flag)
{
	t_doc	*data;

	if ((data = malloc(sizeof(t_doc))))
		return (NULL);
	data->name = ft_strdup(name);
	data->path = ft_strdup(path);
	data->sub_dir = NULL;
	data->stat = NULL;
	data->to_print = NULL;
	data->err;
	if (flag)
	{
		free(path);
		free(name);
	}
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
	char	*(name_path[2]);
	char	*file;

	j = -1;
	if (!(data = malloc(sizeof(t_doc*) * ac - i + 1)))
		ft_error_init();
	while (++j + i < ac)
	{
		file = get_file_name(av[j + i], ls->pwd);
		name_path[0] = ft_strsplit_last(file, '/', 0);
		name_path[1] = ft_strsplit_last(file, '/', 1);
		data[j] = insert_value(name_path[0], name_path[1], 1);
		free(file);
	}
	if (j == 0)
	{
		data[0] = insert_value(".", ls->pwd, 0);
		j++;
	}
	data[j] = NULL;
	ls->arg = data;
}
