/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:31:32 by msorin            #+#    #+#             */
/*   Updated: 2017/11/10 10:31:34 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	c;
	int		my_bool;

	i = 0;
	my_bool = 0;
	while (++i < argc)
	{
		str = argv[i];
		if (*str && !*(str + 1))
			write(1, "test reussit\n", 13);
		else
		{
			my_bool |= i % 2;
		}
		c = my_bool + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return (0);
}
