/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:23:20 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 14:23:22 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putstr_fd(char const *s, int fd)
{
	size_t		size;

	if (s)
	{
		size = ft_strlen(s);
		write(fd, s, size);
	}
}
