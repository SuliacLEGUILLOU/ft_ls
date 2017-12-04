/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:20:28 by msorin            #+#    #+#             */
/*   Updated: 2017/12/04 13:20:30 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static size_t	get_blklen(size_t mode, size_t rdev, size_t blocks)
{
	if (((mode & S_IFCHR) && !(mode & S_IFSOCK))
		|| ((mode & S_IFBLK) == S_IFBLK))
		return (8);
	return (ft_nblen(blocks));
}

t_int4	get_len(t_doc **arg)
{
	t_int4	ret;
	t_int4	tmp;
	t_stat	*s;
	int		i;

	i = -1;
	ret.w = 0;
	ret.x = 0;
	ret.y = 0;
	ret.z = 0;
	while (arg[++i])
	{
		s = arg[i]->stat;
		tmp.w = ft_nblen(s->st_nlink);
		tmp.x = ft_strlen(arg[i]->usr);
		tmp.y = ft_strlen(arg[i]->grp);
		tmp.z = get_blklen(s->st_mode, s->st_rdev, s->st_blocks);
		ret.w = ret.w > tmp.w ? ret.w : tmp.w;
		ret.x = ret.x > tmp.x ? ret.x : tmp.x;
		ret.y = ret.y > tmp.y ? ret.y : tmp.y;
		ret.z = ret.z > tmp.z ? ret.z : tmp.z;
	}
	return (ret);
}

t_int4	get_len1(t_doc **arg)
{
	t_int4	ret;
	t_int4	tmp;
	t_stat	*s;
	int		i;

	i = -1;
	ret.w = 0;
	ret.x = 0;
	ret.y = 0;
	ret.z = 0;
	while (arg[i + 1]->err)
		i++;
	while (!arg[++i]->sub_dir)
	{
		s = arg[i]->stat;
		tmp.w = ft_nblen(s->st_nlink);
		tmp.x = ft_strlen(arg[i]->usr);
		tmp.y = ft_strlen(arg[i]->grp);
		tmp.z = get_blklen(s->st_mode, s->st_rdev, s->blocks);
		ret.w = ret.w > tmp.w ? ret.w : tmp.w;
		ret.x = ret.x > tmp.x ? ret.x : tmp.x;
		ret.y = ret.y > tmp.y ? ret.y : tmp.y;
		ret.z = ret.z > tmp.z ? ret.z : tmp.z;
	}
	return (ret);
}
