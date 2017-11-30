/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:35:16 by msorin            #+#    #+#             */
/*   Updated: 2017/11/29 13:35:18 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

void	clean_t_doc(t_doc *data)
{
	int		i;

	if (data->sub_dir)
	{
		i = -1;
		while (data->sub_dir[++i])
			clean_t_doc(data->sub_dir[i]);
		free(data->sub_dir);
	}
	if (data->name)
		free(data->name);
	if (data->path)
		free(data->path);
	if (data->stat)
		free(data->stat);
	if (data->to_print)
		free(data->to_print);
	if (data->err)
		free(data->err);
	free(data);
}

void	clean_t_tmp(t_tmp *lst)
{
	t_tmp	*t1;
	t_tmp	*t2;

	t1 = lst;
	while (t1)
	{
		t2 = t1;
		t1 = t1->next;
		free(t2->dir);
		free(t2);
	}
}

void	clean_ls(t_ls *ls)
{
	int		i;

	if (ls->pwd)
		free(ls->pwd);
	if (ls->home)
		free(ls->home);
	if (ls->arg)
	{
		i = 0;
		while (ls->arg[i])
		{
			clean_t_doc(ls->arg[i]);
			i++;
		}
	}
	free(ls->arg);
}
