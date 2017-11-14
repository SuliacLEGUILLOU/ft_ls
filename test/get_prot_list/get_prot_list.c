/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prot_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:33:03 by msorin            #+#    #+#             */
/*   Updated: 2017/11/13 09:33:05 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stat	t_stat;

int		main(void)
{
	t_stat	s1;

	lstat("/Users/msorin/Desktop/gh_ft_ls/test/testage", &s1);
	printf("%o s_fifo without '/'\n", s1.st_mode);
	lstat("/Users/msorin/Desktop/gh_ft_ls/test/testage/", &s1);
	printf("%o s_fifo with '/'\n", s1.st_mode);

	printf("\n");

	printf("%o mask file\n", S_IFMT);

	printf("\n");

	printf("%o socket link 's' ('=' with -F)\n", S_IFSOCK);
	printf("%o siymbolic link 'l' ('@' with -F)\n", S_IFLNK);
	printf("%o regular file '-'\n", S_IFREG);
	printf("%o block special file 'b'\n", S_IFBLK);
	printf("%o directory 'd' ('/' with -F)\n", S_IFDIR);
	printf("%o character special file 'c'\n", S_IFCHR);
	printf("%o FIFO 'p' ('|' with -F)\n", S_IFIFO);

	printf("\n");

	printf("%o - %o test with S_IFMT && ~S_IFMT\n", S_IFMT & S_IFSOCK, ~S_IFMT & S_IFSOCK);
	printf("%o - %o test with S_IFMT && ~S_IFMT\n", S_IFMT & S_IFLNK, ~S_IFMT & S_IFLNK);
	printf("%o - %o test with S_IFMT && ~S_IFMT\n", S_IFMT & S_IFREG, ~S_IFMT & S_IFREG);
	printf("%o - %o test with S_IFMT && ~S_IFMT\n", S_IFMT & S_IFBLK, ~S_IFMT & S_IFBLK);
	printf("%o - %o test with S_IFMT && ~S_IFMT\n", S_IFMT & S_IFDIR, ~S_IFMT & S_IFDIR);
	printf("%o - %o test with S_IFMT && ~S_IFMT\n", S_IFMT & S_IFCHR, ~S_IFMT & S_IFCHR);
	printf("%o - %o test with S_IFMT && ~S_IFMT\n", S_IFMT & S_IFIFO, ~S_IFMT & S_IFIFO);

	printf("\n");

	printf("%o ..S...... (..s...... if +x)\n", S_ISUID);
	printf("%o .....S... (.....s... if +x)\n", S_ISGID);
	printf("%o ........T (........t if +x)\n", S_ISVTX);

	printf("\n");

	printf("%o rwx...... (rws...... if S_ISUID) ('*' with -F)\n", S_IRWXU);
	printf("%o rw-......\n", S_IRUSR + S_IWUSR);
	printf("%o r-x...... (r-s...... if S_ISUID) ('*' with -F)\n", S_IRUSR + S_IXUSR);
	printf("%o r--......\n", S_IRUSR);
	printf("%o -wx...... (-ws...... if S_ISUID) ('*' with -F)\n", S_IWUSR + S_IXUSR);
	printf("%o -w-......\n", S_IWUSR);
	printf("%o --x...... (--s...... if S_ISUID) ('*' with -F)\n", S_IXUSR);

	printf("\n");

	printf("%o ...rwx... (...rws.... if S_ISGID) ('*' with -F)\n", S_IRWXG);
	printf("%o rw-......\n", S_IRGRP + S_IWGRP);
	printf("%o ...r-x... (...r-s... if S_ISGID) ('*' with -F)\n", S_IRGRP + S_IXGRP);
	printf("%o ...r--...\n", S_IRGRP);
	printf("%o ...-wx... (...-ws... if S_ISGID) ('*' with -F)\n", S_IWGRP + S_IXGRP);
	printf("%o ...-w-...\n", S_IWGRP);
	printf("%o ...--x... (...--s... if S_ISGID) ('*' with -F)\n", S_IXGRP);

	printf("\n");

	printf("%o ......rwx (......rws if S_ISVTX) ('*' with -F)\n", S_IRWXO);
	printf("%o ......rw-\n", S_IROTH + S_IWOTH);
	printf("%o ......r-x (......r-s if S_ISVTX) ('*' with -F)\n", S_IROTH + S_IXOTH);
	printf("%o ......r--\n", S_IROTH);
	printf("%o ......-wx (-ws...... if S_ISUID) ('*' with -F)\n", S_IWOTH + S_IXOTH);
	printf("%o ......-w-\n", S_IWOTH);
	printf("%o ......--x (......--s if S_ISVTX) ('*' with -F)\n", S_IXOTH);

	return (0);
}
