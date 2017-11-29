/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:44:21 by msorin            #+#    #+#             */
/*   Updated: 2017/11/23 15:44:41 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	*double_color(const char *cs1, const char *cs2, char *str)
{
	char	*ret;

	ret = ft_strjoin_f((char *)cs1, (char*)cs2, 0);
	ret = ft_strjoin_f(ret, str, 3);
	return (ret);
}

static char	*first_cut(char *str, int mode)
{
	char	*ret;

	if (!(mode & S_FUGID))
		ret = ft_strjoin_f(C31, str, 2);
	else if (!(mode & S_ISUID))
		ret = double_color(C46, C30, str);
	else
		ret = double_color(C41, C30, str);
	return (ret);
}

static char	*second_cut(char *str, int mode)
{
	char	*ret;

	if (!(mode & S_IWOTH))
		ret = ft_strjoin_f(C34, str, 2);
	else if (!(mode & S_IDVTX))
		ret = double_color(C43, C30, str);
	else
		ret = double_color(C42, C30, str);
	return (ret);
}

char		*set_color(char *str, int mode)
{
	char	*ret;

	if ((mode & S_IFREG) && !(mode & S_IFBLK) && !(mode & S_IXUGO))
		return (str);
	if (mode & S_IFIFO)
		ret = ft_strjoin_f(C33, str, 2);
	if ((mode & S_IFSOCK) == S_IFSOCK)
		ret = ft_strjoin_f(C32, str, 2);
	if ((mode & S_IFLNK) == S_IFLNK)
		ret = ft_strjoin_f(C35, str, 2);
	if ((mode & S_IFBLK) == S_IFBLK)
		ret = double_color(C46, C34, str);
	if ((mode & S_IFREG) && !(mode & S_IFBLK))
		ret = first_cut(str, mode);
	if ((mode & S_IFDIR) && !(mode & S_IFLNK))
		ret = second_cut(str, mode);
	if ((mode & S_IFCHR) && !(mode & S_IFSOCK))
		ret = double_color(C43, C34, str);
	return ((ret = ft_strjoin_f(ret, RESET, 1)));
}
