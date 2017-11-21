/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:20:38 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 14:20:41 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_swap_sign(int *n, char **str, int *count)
{
	if (*n < 0)
	{
		*str[*count] = '-';
		*count = *count + 1;
		*n = *n * (-1);
	}
}

static char		*ft_tab_for_char(int n, int size)
{
	char	*tab;

	if (n < 0)
	{
		tab = (char *)malloc((size + 2) * sizeof(char));
		return (tab);
	}
	else
	{
		tab = (char *)malloc((size + 1) * sizeof(char));
		return (tab);
	}
}

static int		ft_power_ten(int n)
{
	unsigned int	number;

	number = 1;
	while (n > 1)
	{
		number = number * 10;
		n--;
	}
	return (number);
}

static int		ft_nbr_nbr(int n)
{
	unsigned int	number;

	number = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		number++;
	}
	number++;
	return (number);
}

char			*ft_itoa(int n)
{
	int		size;
	int		divide;
	int		count;
	char	*str;

	size = ft_nbr_nbr(n);
	str = ft_tab_for_char(n, size);
	if (!str)
		return (NULL);
	count = 0;
	divide = ft_power_ten(size);
	ft_swap_sign(&n, &str, &count);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	while (size > 0)
	{
		str[count] = (n / divide) + '0';
		size--;
		n = n % divide;
		divide = divide / 10;
		count++;
	}
	str[count] = '\0';
	return (str);
}
