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

char	*set_clasify(char *str, int mode);
char	*set_detail(char *str, t_stat *st);

void	get_detail(t_doc **aff, int i, t_mask opt)
{
	char	*str;

	str = aff[i]->to_print;
	if (!(opt & DETAIL) && !(opt & COLOR) && !(opt & CLASSIFY))
		return ;
	if (opt & COLOR)
		str = set_color(str, aff[i]->stat->st_mode);
	if (opt & CLASSIFY)
		str = set_clasify(str, aff[i]->stat->st_mode);
	if (opt & DETAIL)
		str = set_detail(str, aff[i]->stat);
}
