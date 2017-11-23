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

static char	*set_clasify(char *str, int mode)
{
	char	*ret;

	if (mode & S_IFSOCK)
		ret = ft_strjoin_f(str, "=", 1);
	if (mode & S_IFLNK)
		ret = ft_strjoin_f(str, "@", 1);
	if ((mode & S_IFDIR) && !(mode & S_IFLNK))
		ret = ft_strjoin_f(str, "/", 1);
	if (mode & S_IFIFO)
		ret = ft_strjoin_f(str, "|", 1);
	return (ret);
}

void		get_detail(t_doc **aff, int i, t_mask opt)
{
	char	*str;

	str = aff[i]->to_print;
	if (!(opt & DETAIL) && !(opt & COLOR) && !(opt & CLASSIFY))
		return ;
	if (opt & COLOR)
		str = set_color(str, aff[i]->stat->st_mode);
	if (opt & CLASSIFY)
		str = set_clasify(str, aff[i]->stat->st_mode);
	if (opt & DETAIL)
		str = set_detail(str, aff[i]->stat);
}
