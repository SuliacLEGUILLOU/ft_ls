/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_notadirectory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:53:03 by msorin            #+#    #+#             */
/*   Updated: 2017/11/14 10:53:06 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/stat.h>

typedef struct stat	t_stat;

int	main(void)
{
	DIR		*d;
	t_stat	t;
	char	*str;
	int		e;
	char	test[256] = "unfichierinexistant";

	if (lstat(test, &t))
	{
		e = errno;
		str = strerror(e);
		perror("lstat");
		printf("%s - %d\n", str, e);
	}
	else
		printf("%o\n", t.st_mode);
	d = opendir(test);
	e = errno;
	str = strerror(e);
	perror("test");
	printf("%s - %d\n", str, e);
	return (0);
}
