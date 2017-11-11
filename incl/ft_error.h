/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:00:37 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 14:24:36 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <ft_ls.h>
# include <structure.h>

void	ft_error_init(void);
void	ft_error_malloc(t_ls *ls);
void	ft_error_illegal_opt(char f, t_ls *ls);

#endif
