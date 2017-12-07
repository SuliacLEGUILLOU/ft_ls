/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:44:46 by msorin            #+#    #+#             */
/*   Updated: 2017/12/07 16:44:47 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	*get_minor_major(int rdev)
{
	size_t	i;
	char	*s1;
	char	*s2;
	char	*ret;

	s1 = ft_itoa(MAJOR(rdev));
	s2 = ft_itoa(MINOR(rdev));
	ret = ft_strjoin_f(s1, ",", 1);
	i = 0;
	while (++i <= 4 - ft_strlen(s2))
		ret = ft_strjoin_f(ret, " ", 1);
	ret = ft_strjoin_f(ret, s2, 3);
	return (ret);
}

char	*get_blocks(char *str, t_stat *st, int blk)
{
	char	*ret;

	if (((st->st_mode & S_IFCHR) && !(st->st_mode & S_IFSOCK))
		|| ((st->st_mode & S_IFBLK) == S_IFBLK))
		ret = get_minor_major(st->st_rdev);
	else
		ret = ft_itoa(st->st_size);
	while (blk - ft_strlen(ret))
		ret = ft_strjoin_f(" ", ret, 2);
	ret = ft_strjoin_f(ret, " ", 1);
	ret = ft_strjoin_f(ret, str, 3);
	return (ret);
}
