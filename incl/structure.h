/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:41:44 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 17:54:06 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <sys/stat.h>
# include <dirent.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dir;
typedef struct passwd	t_pass;
typedef struct group	t_grp;

typedef int				t_mask;
typedef unsigned long	size_t;

typedef struct s_int4	t_int4;
typedef struct s_tmp	t_tmp;
typedef struct s_doc	t_doc;
typedef struct s_ls		t_ls;

struct	s_int4
{
	int		w;
	int		x;
	int		y;
	int		z;
};

struct	s_tmp
{
	int		nb;
	t_dir	*dir;
	t_tmp	*next;
};

struct	s_doc
{
	char	*name;
	char	*path;
	char	*usr;
	char	*grp;
	size_t	mtime;
	t_doc	**sub_dir;
	t_stat	*stat;
	char	*to_print;
	char	*err;
};

struct	s_ls
{
	t_mask	opt;
	char	*pwd;
	char	*home;
	t_doc	**arg;
	int		error;
};

#endif
