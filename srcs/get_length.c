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

static size_t	st_get_blklen(size_t mode, size_t blocks)
{
	if (((mode & S_IFCHR) && !(mode & S_IFSOCK))
		|| ((mode & S_IFBLK) == S_IFBLK))
		return (8);
	return (ft_nblen(blocks));
}

static t_int4	st_baselen(t_stat *s, t_doc *arg, t_mask opt)
{
	t_int4	tmp;

	tmp.w = 0;
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	if (arg->name[0] == '.' && !(opt & (ALL + ALL_MAJ)))
		return (tmp);
	if (!(opt & ALL) && !(ft_strcmp(arg->name, ".")
		&& ft_strcmp(arg->name, "..")))
		return (tmp);
	tmp.w = ft_nblen(s->st_nlink);
	tmp.x = ft_strlen(arg->usr);
	tmp.y = ft_strlen(arg->grp);
	tmp.z = st_get_blklen(s->st_mode, s->st_size);
	return (tmp);
}

t_int4			get_len(t_doc **arg, t_mask opt)
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
		tmp = st_baselen(s, arg[i], opt);
		ret.w = ret.w > tmp.w ? ret.w : tmp.w;
		ret.x = ret.x > tmp.x ? ret.x : tmp.x;
		ret.y = ret.y > tmp.y ? ret.y : tmp.y;
		ret.z = ret.z > tmp.z ? ret.z : tmp.z;
	}
	return (ret);
}

t_int4			get_len1(t_ls *ls)
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
	while (ls->arg[i + 1] && ls->arg[i + 1]->err)
		i++;
	while (ls->arg[++i] && !ls->arg[i]->sub_dir)
	{
		s = ls->arg[i]->stat;
		tmp = st_baselen(s, ls->arg[i], ls->opt);
		ret.w = ret.w > tmp.w ? ret.w : tmp.w;
		ret.x = ret.x > tmp.x ? ret.x : tmp.x;
		ret.y = ret.y > tmp.y ? ret.y : tmp.y;
		ret.z = ret.z > tmp.z ? ret.z : tmp.z;
	}
	return (ret);
}
