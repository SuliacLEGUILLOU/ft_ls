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

static char	*set_time(const char *hour, int is_far)
{
	char	*ret;

	if (is_far)
		ret = ft_strdup(hour);
	else
	{
		ret = ft_strndup(hour + 4, 7);
		ret = ft_strjoin_f(ret, ft_strndup(hour + 19, 5), 3);
	}
	return (ret);
}

static char	*add_time(char *str, time_t t)
{
	char	*ret;
	char	*tmp;
	time_t	now;

	now = time(NULL);
	tmp = ctime(&t);
	if (time(NULL) >= t)
		ret = ft_strndup(tmp + 4, 12);
	else
	{
		if ((t < now - 15778476) || (t > now))
			ret = set_time(tmp, 1);
		else
			ret = set_time(tmp, 0);
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
