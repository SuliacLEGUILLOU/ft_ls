/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:35:25 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 11:35:29 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <stdio.h>

void	fill_struct_file(t_doc **arg, int i, t_mask opt, t_int4 len)
{
	if (opt & (DETAIL | COLOR | CLASSIFY))
		get_detail(arg, i, opt, len);
	else
		arg[i]->to_print = ft_strdup(arg[i]->name);
}

void	recur_dir(t_doc **data, t_mask opt, int i, t_ls *ls)
{
	DIR		*d;

	if (data[i]->name[0] == '.' && !(opt & (ALL + ALL_MAJ)))
		return ;
	if (!((data[i]->stat->st_mode & S_IFDIR)
		&& !(data[i]->stat->st_mode & S_IFLNK)))
		return ;
	if (!ft_strcmp(data[i]->name, ".") || !ft_strcmp(data[i]->name, ".."))
		return ;
	ft_putchar('\n');
	if (!(d = opendir(data[i]->path)))
		data[i]->err = set_error(data[i]->path, errno);
	else
	{
		if (data[i]->to_print)
		{
			free(data[i]->to_print);
			data[i]->to_print = NULL;
		}
		fill_struct_dir(data, i, d, opt);
		closedir(d);
	}
	ft_print_data(data[i]);
	if (!data[i]->err)
		print_subdir(data[i]->sub_dir, opt, ls);
}

void	print_subdir(t_doc **data, t_mask opt, t_ls *ls)
{
	int		i;
	t_int4	len;

	len = get_len(data, ls->opt);
	i = -1;
	while (data[++i])
	{
		if (data[i]->name[0] == '.' && !(opt & (ALL + ALL_MAJ)))
			continue ;
		if (!(opt & ALL) && !(ft_strcmp(data[i]->name, ".")
			&& ft_strcmp(data[i]->name, "..")))
			continue ;
		fill_struct_file(data, i, opt, len);
		ft_print_data(data[i]);
	}
	if (!(opt & RECUR))
		return ;
	i = -1;
	while (data[++i])
	{
		if ((data[i]->stat->st_mode & S_IFDIR) == S_IFDIR)
			recur_dir(data, opt, i, ls);
		clean_t_doc(data[i]);
		data[i] = NULL;
	}
}

void	print_ls(t_ls *ls)
{
	int		i;

	i = 0;
	while (ls->arg[i])
	{
		if (i && ls->arg[i]->sub_dir)
			ft_putchar('\n');
		ft_print_data(ls->arg[i]);
		if (ls->arg[i]->sub_dir)
			print_subdir(ls->arg[i]->sub_dir, ls->opt, ls);
		i++;
	}
}
