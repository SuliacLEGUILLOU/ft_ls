/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 11:58:02 by msorin            #+#    #+#             */
/*   Updated: 2013/12/01 11:58:03 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_putnbr(unsigned int t)
{
	if (t < 10)
		ft_putchar(t + 48);
	else
	{
		set_putnbr(t / 10);
		ft_putchar((t % 10) + 48);
	}
}

void	ft_putnbr(int n)
{
	unsigned int	t;

	if (n < 0)
	{
		ft_putchar('-');
		t = -n;
	}
	else
		t = n;
	set_putnbr(t);
}
