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

t_stat	*copy_stat(t_stat *st)
{
	t_stat	*ret;

	ret = malloc(sizeof(t_stat));
	ret->st_dev = st->st_dev;
	ret->st_ino = st->st_ino;
	ret->st_mode = st->st_mode;
	ret->st_nlink = st->st_nlink;
	ret->st_uid = st->st_uid;
	ret->st_gid = st->st_gid;
	ret->st_rdev = st->st_rdev;
	ret->st_size = st->st_size;
	ret->st_blksize = st->st_blksize;
	ret->st_blocks = st->st_blocks;
	ret->st_atime = st->st_atime;
	ret->st_mtime = st->st_mtime;
	ret->st_ctime = st->st_ctime;
	free(st);
	return (ret);
}
