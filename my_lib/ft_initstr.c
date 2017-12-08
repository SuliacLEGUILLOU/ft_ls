/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:47:19 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 12:49:40 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_initstr(char c, int sz)
{
	int		i;
	char	*ret;

	if (!(ret = ft_strnew(sz)))
		return (NULL);
	i = -1;
	while (++i < sz)
		ret[i] = c;
	return (ret);
}
