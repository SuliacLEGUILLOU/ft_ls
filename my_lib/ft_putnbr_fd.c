/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 11:57:00 by msorin            #+#    #+#             */
/*   Updated: 2013/12/01 11:57:02 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_putnbr_fd(unsigned int t, int fd)
{
	if (t < 10)
		ft_putchar_fd(t + 48, fd);
	else
	{
		set_putnbr_fd(t / 10, fd);
		ft_putchar_fd((t % 10) + 48, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	t;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		t = -n;
	}
	else
		t = n;
	set_putnbr_fd(t, fd);
}
