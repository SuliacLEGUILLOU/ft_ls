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

int		ft_ls(t_ls *ls, t_int4 len1);
int		ft_print_data(t_doc *data);
int		is_flag(const char *arg, t_ls *ls);
int		need_swap(t_doc *s1, t_doc *s2, t_mask opt);

char	*add_time(char *str, time_t t);
char	*get_blocks(char *str, t_stat *st, int blk);
char	*set_color(char *str, int mode);
char	*set_detail(char *str, t_stat *st, t_int4 length);

void	clean_ls(t_ls *ls);
void	clean_t_doc(t_doc *data);
void	clean_t_tmp(t_tmp *lst);
void	fill_struct_dir(t_doc **arg, int i, DIR *dir, t_mask opt);
void	get_detail(t_doc **aff, int i, t_mask opt, t_int4 len);
void	set_arg(t_ls *ls, char **av, int ac, int i);
void	sort_indir(t_doc **data, t_mask opt);
void	sort_file_list(t_ls *ls);
void	print_subdir(t_doc **data, t_mask opt, t_ls *ls);
void	recur_dir(t_doc **data, t_mask opt, int i, t_ls *ls);

t_dir	*copy_dirent(t_dir *src);

t_doc	*insert_value(char *name, char *path, int flag, int init);

t_int4	get_len(t_doc **arg);
t_int4	get_len1(t_ls *ls);

#endif
