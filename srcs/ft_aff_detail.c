/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_detail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:08:20 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 18:08:21 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	*double_color(const char *cs1, const char *cs2, char *str);

static char	*set_color(char *str, int mode)
{
	char	*ret;

	if ((mode & IFREG) && !(mode & S_IFBLK) && !(mode & S_IXUGO))
		return (str);
	if ((mode & S_IFREG) && (mode & S_IXUG)
		&& !(mode & S_IFBLK) && !(mode & S_FUGID))
		ret = ft_strjoin_f(C31, str, 2);
	if ((mode & S_IFSOCK) == S_IFSOCK)
		ret = ft_strjoin_f(C32, str, 2);
	if (mode & S_IFIFO)
		ret = ft_strjoin_f(C33, str, 2);
	if ((mode & S_IFDIR) && !(mode & S_IFLNK) && !(mode & S_IWUGO))
		ret = ft_strjoin_f(C34, str, 2);
	if ((mode & S_IFLNK) == S_IFLNK)
		ret = ft_strjoin_f(C35, str, 2);
	if ((mode & S_IFREG) && (mode & S_IXUSR)
		&& !(mode & S_IFBLK) && (mode & S_ISUID))
		ret = double_color(C41, C30, str);
	if ((mode & S_IFDIR) && !(mode & S_IFLNK)
		&& (mode & S_IWUGO) && (mode & S_IDVTX))
		ret = double_color(C42, C30, str);
	if ((mode & S_IFDIR) && !(mode & S_IFLNK)
		&& (mode & S_IWUGO) && !(mode & S_IDVTX))
		ret = double_color(C43, C30, str);
	if ((mode & S_IFCHR) & !(mode & S_IFSOCK))
		ret = double_color(C43, C34, str);
	if ((mode & S_IFREG) && (mode & S_IXUSR) && !(mode & S_IFBLK)
		&& !(mode & S_ISUID) && (mode & S_ISGID))
		ret = double_color(C46, C30, str);
	if ((mode & S_IFBLK) == S_IFBLK)
		ret = double_color(C46, C34, str);
	ret = ft_strjoin_f(ret, RESET, 1);
}

void		get_detail(t_doc **aff, int i, t_mask opt)
{
	char	*str;

	str = aff[i]->to_print;
	if (!(opt & DETAIL) && !(opt & COLOR) && !(opt & CLASIFY))
		return ;
	if (opt & COLOR)
		str = set_color(str, aff[i]->stat->st_mode);
	if (opt & CLASIFY)
		str = set_clasify(str, aff[i]->stat->st_mode);
	if (opt & DETAIL)
		str = set_detail(str, aff[i]->stat);
}
