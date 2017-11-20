/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_detail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:08:20 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 18:08:21 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	get_detail(t_doc **aff, i, t_mask opt)
{
	char	*str;

	str = aff->to_print;
	if (!(opt & DETAIL) && !(opt & COLOR) && !(opt & CLASIFY))
		return ;
}
