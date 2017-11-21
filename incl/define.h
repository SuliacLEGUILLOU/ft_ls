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

/*
** define color
** C30 Black
** C31 Red
** C34 Blue
** C35 Purple
** C41 FRed
** C42 FGreen
** C43 FYellow
** C46 FLBlue
** C94 DPurple
** C95 LPurple
*/

# define C30 "\x1B[30m"
# define C31 "\x1B[31m"
# define C34 "\x1B[34m"
# define C35 "\x1B[35m"
# define C41 "\x1B[41m"
# define C42 "\x1B[42m"
# define C43 "\x1B[43m"
# define C46 "\x1B[46m"
# define RESETNDL "\033[0m\n"
# define RESET "\033[0m"

#endif
