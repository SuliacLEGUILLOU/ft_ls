/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:07:40 by msorin            #+#    #+#             */
/*   Updated: 2017/12/07 14:07:42 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <time.h>

char		*add_time(char *str, time_t t)
{
	char	*ret;
	char	*tmp;
	time_t	now;

	now = time(NULL);
	tmp = ctime(&t);
	if ((t < now - 15778476) || (t > now))
	{
		ret = ft_strndup(tmp + 4, 7);
		ret = ft_strjoin_f(ret, ft_strndup(tmp + 19, 5), 3);
	}
	else
		ret = ft_strndup(tmp + 4, 12);
	ret = ft_strjoin_f(ret, " ", 1);
	ret = ft_strjoin_f(ret, str, 3);
	return (ret);
}
