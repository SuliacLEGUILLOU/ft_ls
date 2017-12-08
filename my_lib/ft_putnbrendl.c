/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:37:27 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 17:38:40 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	st_putinbase(size_t nb, size_t base, char ech[17])
{
	if (!nb)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb / base)
		st_putinbase(nb / base, base, ech);
	write(1, ech + (nb % base), 1);
}

void		ft_putnbrendl(size_t n, size_t base)
{
	char	ech[17];
	int		i;

	i = -1;
	while (++i < 10)
		ech[i] = i + '0';
	i--;
	while (++i < 16)
		ech[i] = i - 10 + 'a'; 
	st_putinbase(n, base, ech);
	ft_putchar('\n');
}
