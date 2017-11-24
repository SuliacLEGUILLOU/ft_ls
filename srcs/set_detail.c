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

static char	*add_time(char *str, time_t t)
{
	(void)str;
	(void)t;
	return (NULL);
}

char	*set_detail(char *str, t_stat *st)
{
	char	*ret;

	ret = add_time(str, st->st_ctime);
	return (NULL);
}
