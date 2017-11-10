/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:41:44 by msorin            #+#    #+#             */
/*   Updated: 2017/11/10 11:41:45 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_opt	t_opt;
typedef struct s_doc	t_doc;
typedef struct s_ls		t_ls;

struct	s_opt
{
	char	lst;
	char	rec;
	char	all;
	char	rev;
	char	tmp;
	char	opt;
};

struct	s_doc
{
	char	*name;
	size_t	ctime;
	t_doc	**sub_dir;
	t_stat	*data;
	char	*to_print;
};


struct	s_ls
{
	t_opt	opt;
	t_doc	**av;
};

#endif
