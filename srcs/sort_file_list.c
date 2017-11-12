/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:51:45 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 16:06:23 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	insert_nonstat(t_ls *ls, int i)
{
	int		j;
	t_doc	*t1;
	t_doc	*t2;

	j = 0
	t1 = ls->arg[i];
	while (ls->arg[j]->stat)
}

static void	sort_data(t_ls *ls, int i)
{
	int	j;
	t_doc	*t1;
	t_doc	*t2;

	j = -1;
	t1 = ls->arg[i];
	while (++j < i)
	{
		if (!ls->arg[j]->stat)
			continue ;
		if (ft_strcmp(t1->name, ls->arg[j]->name) < 0)
		{
			t2 = ls->arg[j];
			ls->arg[j] = t1;
			t1 = t2;
		}
	}
	ls->arg[i] = t1;
}

void	sort_file_list(t_ls *ls)
{
	int		i;
	int		j;

	i = -1;
	while (ls->arg[++i])
	{
		if (lstat(ls->arg[i]->name, ls->arg[i]->stat) && !ls->error)
			ls->error = 1;
		if (ls->opt & NO_SORT)
			continue ;
	}
}
