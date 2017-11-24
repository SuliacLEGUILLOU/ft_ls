/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:49:05 by msorin            #+#    #+#             */
/*   Updated: 2017/11/02 14:57:18 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Nov  2 11:06
Jun 15 16:19
Thu Nov  2 14:57:26 2017

1511538372 + 31104000

*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>

char	ech[17] = "0123456789ABCDEF";

char	*ft_split_time(char *str)
{
	char	*ret;
	char	*t;
	int		i;

	if (!(ret = (char*)malloc(sizeof(char) * 13)))
		return (NULL);
	t = str + 4;
	i = -1;
	while (++i < 12)
		ret[i] = t[i];
	ret[12] = '\0';
	return(ret);
}

int		ft_strlen(char *s)
{
	if (!s)
		return (-1);
	if (!(*s))
		return (0);
	return (1 + ft_strlen(s + 1));
}

void	ft_putnbr_base(size_t nb, int base)
{
	char	c;

	if (nb / base)
		ft_putnbr_base(nb / base, base);
	c = ech[(nb % base)];
	write(1, &c, 1);
}

void	ft_putnbr_base_ndl(int nb, int base)
{
	size_t	t;

	if (!nb)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			t = 0 - nb;
		}
		else
			t = nb;
		ft_putnbr_base(t, base);
	}
	write(1, "\n", 1);
}

int		main(void)
{
	char	*str;
	time_t	*q;

	q = malloc(sizeof(time_t));
	*q = 1511538372 + 311040000; //time(q);// = i;
	str = ctime(q);
	ft_putnbr_base_ndl(*q, 10);
	write(1, str, ft_strlen(str));
	free(q);
	return (0);
}
