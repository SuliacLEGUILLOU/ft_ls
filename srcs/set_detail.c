/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_detail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:15:54 by msorin            #+#    #+#             */
/*   Updated: 2017/11/23 16:15:58 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <unistd.h>

static char	*st_add_slink(char *str, char *path)
{
	char	*ret;
	char	buff[1024];
	ssize_t	cnt;

	if ((cnt = readlink(path, buff, 1024)) < 0)
		return (str);
	ret = ft_strjoin_f(str, " -> ", 1);
	ret = ft_strjoin_f(ret, buff, 1);
	return (ret);
}

char		*set_detail(char *str, t_doc *data, t_int4 lenght)
{
	char	*ret;

	ret = add_time(str, data->stat->st_mtime);
	ret = get_blocks(ret, data->stat, lenght.z);
	ret = get_gu_name(ret, data->grp, lenght.y);
	ret = get_gu_name(ret, data->usr, lenght.x);
	ret = get_nlink(ret, data->stat->st_nlink, lenght.w);
	ret = get_mode(ret, data->stat->st_mode, data->path);
	if ((data->stat->st_mode & S_IFLNK) == S_IFLNK)
		ret = st_add_slink(ret, data->path);
	return (ret);
}
