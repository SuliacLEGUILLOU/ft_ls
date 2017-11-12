/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:41:44 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 16:12:12 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <sys/stat.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dir;

typedef short			t_mask;
typedef unsigned long	size_t;

typedef struct s_tmp	t_tmp;
typedef struct s_doc	t_doc;
typedef struct s_ls		t_ls;

struct	s_tmp
{
	int		nb;
	t_dir	*dir;
	t_tmp	*next;
};

struct	s_doc
{
	char	*name;
	size_t	ctime;
	t_doc	**sub_dir;
	t_stat	*stat;
	char	*to_print;
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
