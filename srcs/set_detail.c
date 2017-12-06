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
#include <time.h>

static char	*add_time(char *str, time_t t)
{
	char	*ret;
	char	*tmp;

	tmp = ctime(&t);
	if (time(NULL) >= t)
		ret = ft_strndup(tmp + 4, 12);
	else
	{
		ret = ft_strndup(tmp + 4, 7);
		ret = ft_strjoin_f(ret, ft_strndup(tmp + 19, 5), 3);
	}
	ret = ft_strjoin_f(ret, " ", 1);
	ret = ft_strjoin_f(ret, str, 1);
	return (ret);
}

char		*set_detail(char *str, t_stat *st, t_int4 lenght)
{
	char	*ret;

	(void)lenght;
	ret = add_time(str, st->st_mtime);
	return (ret);
}
