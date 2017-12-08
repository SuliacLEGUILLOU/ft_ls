/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:08:58 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 13:08:59 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*get_nlink(char *str, int nlink, int len)
{
	char	*ret;
	char	*sint;
	int		tlen;

	tlen = ft_nblen(nlink);
	if (len != tlen)
		ret = ft_initstr(32, len - tlen);
	else
		ret = ft_strnew(0);
	sint = ft_itoa(nlink);
	ret = ft_strjoin_f(ret, sint, 3);
	ret = ft_strjoin_f(ret, " ", 1);
	ret = ft_strjoin_f(ret, str, 3);
	return (ret);
}
