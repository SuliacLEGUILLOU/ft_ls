/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:46:43 by msorin            #+#    #+#             */
/*   Updated: 2017/11/29 15:48:51 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_print_data(t_doc *data)
{
	if (data->err)
	{
		ft_putendl_fd(data->err, 2);
		return (1);
	}
	ft_putendl(data->to_print);
	return (0);
}
