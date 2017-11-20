/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:39:04 by msorin            #+#    #+#             */
/*   Updated: 2017/11/11 15:16:09 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define DETAIL		1
# define RECUR		2
# define ALL		4
# define ALL_MAJ	8
# define REVERSE	16
# define TIME		32
# define NO_SORT	64
# define CLASSIFY	128
# define COLOR		256
# define nul		'\0'
# define MINOR(x)	(x & 0xff)
# define MAJOR(x)	(x >> 24)

#endif
