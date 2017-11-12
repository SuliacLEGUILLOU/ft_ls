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

void	sort_file_list(t_ls *ls)
{
	int		i;
	t_doc	*tmp;

	i = -1;
	while (ls->data[++i])
	{
		if (lstat(ls->data[i]->name, ls->data[i]->data) && ls->error != 1)
			ls->error = 1;
	}
}