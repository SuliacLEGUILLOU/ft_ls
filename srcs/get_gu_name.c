/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gu_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:43:51 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 12:43:52 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*get_gu_name(char *str, char *gu, int len)
{
	char	*ret;
	int		tlen;

	tlen = ft_strlen(gu);
	ret = ft_initstr(32, len - tlen + 2);
	ret = ft_strjoin_f(gu, ret, 2);
	ret = ft_strjoin_f(ret, str, 3);
	return (ret);
}
