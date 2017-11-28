/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:50:06 by msorin            #+#    #+#             */
/*   Updated: 2017/11/17 12:16:28 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "define.h"
# include "ft_error.h"
# include "structure.h"

# include <stddef.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <dirent.h>

/*
** needed in order to don't have leaks
*/
void	clear_ls(t_ls *ls);

/*
** set_flag seems to be used only in is_flag, moved to static 
** void	set_flag(t_ls *ls, char f);
*/

int		is_flag(const char *arg, t_ls *ls);

int		ft_ls(t_ls *ls);
void	sort_file_list(t_ls *ls);

void	set_arg(t_ls *ls, char **av, int ac, int i);

t_dir	*copy_dirent(t_dir *src);
t_stat	*copy_stat(t_stat *st);
void	st_fill_struct_dir(t_doc **arg, int i, DIR *dir, t_mask opt);

void	get_detail(t_doc **aff, int i, t_mask opt);
char	*set_color(char *str, int mode);
char	*set_detail(char *str, t_stat *st);//, int nlink, int ttsize);

void	debug_print_arg(t_doc *arg);//

#endif
