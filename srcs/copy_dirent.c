/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dirent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:59:35 by msorin            #+#    #+#             */
/*   Updated: 2017/11/17 14:00:18 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

t_dir	*copy_dirent(t_dir *src)
{
	t_dir	*ret;
	int		i;

	ret = malloc(sizeof(t_dir));
	ret->d_ino = src->d_ino;
	ret->d_seekoff = src->d_seekoff;
	ret->d_reclen = src->d_reclen;
	ret->d_namlen = src->d_namlen;
	ret->d_type = src->d_type;
	i = -1;
	while (src->d_name[++i])
		ret->d_name[i] = src->d_name[i];
	ret->d_name[i] = '\0';
	return (ret);
}
