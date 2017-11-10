/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:50:06 by msorin            #+#    #+#             */
/*   Updated: 2017/10/30 16:50:08 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <ft_error.h>

# define F1	1
# define F2 2
# define F3 4
# define F4 8
# define F5 16

typedef struct s_opt	t_opt;
typedef struct s_doc	t_doc;
typedef struct s_ls		t_ls;

struct	s_opt
{
	int		lst;
	int		rec;
	int		all;
	int		rev;
	int		tmp;
};

struct	s_doc
{
	char	*name;
	size_t	ctime;
	t_doc	**sub;
	t_stat	*data;
};

struct	s_ls
{
	t_opt	*opt;
	t_doc	**av;
};

int		somme_opt(t_opt *opt);

#endif
