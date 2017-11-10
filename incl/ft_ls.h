/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:50:06 by msorin            #+#    #+#             */
/*   Updated: 2017/11/10 11:43:45 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <define.h>
# include <ft_error.h>
# include <structure.h>

# include <stddef.h>

void	clear_ls(t_ls *ls);
void	set_flag(t_ls *ls, char f);

int		is_flag(const char *arg, t_ls *ls);

#endif
