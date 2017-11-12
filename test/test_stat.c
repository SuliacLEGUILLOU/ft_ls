/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:47:19 by msorin            #+#    #+#             */
/*   Updated: 2017/11/12 14:47:20 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>

typedef struct stat	t_stat;

int		main(void)
{
	t_stat	*t;

	t = NULL;
	if (stat("/un/dossier/inexistant", t))
		write(2, "Mon erreur\n", 11);
	return (0);
}
