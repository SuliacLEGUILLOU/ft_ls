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

#define S_IXUGO 73

typedef struct stat	t_stat;

void	print_binari(int nb)
{
	if (!(nb % 2) && !(nb / 2))
		printf("0");
	if (nb / 2)
		print_binari(nb / 2);
	printf("%d", nb % 2);
}

int		main(void)
{
	t_stat	s1;

	// lstat("/Users/msorin/Desktop/gh_ft_ls/test/testage", &s1);
	// printf("%o s_fifo without '/'\n", s1.st_mode);
	// lstat("/Users/msorin/Desktop/gh_ft_ls/test/testage/", &s1);
	// printf("%o s_fifo with '/'\n", s1.st_mode);

	printf("%o\n", S_IXUGO);
	printf("%o\n", S_ISUID + S_ISGID + S_ISVTX);

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

	print_binari(S_IFSOCK);
	printf(" s--------- S_IFSOCK\n");
	print_binari(S_IFLNK);
	printf(" l--------- S_IFLNK\n");
	print_binari(S_IFREG);
	printf(" ---------- S_IFREG\n0");
	print_binari(S_IFBLK);
	printf(" b--------- S_IFBLK\n0");
	print_binari(S_IFDIR);
	printf(" d--------- S_IFDIR\n00");
	print_binari(S_IFCHR);
	printf(" c--------- S_IFCHR\n000");
	print_binari(S_IFIFO);
	printf(" p--------- S_IFIFO\n");


	printf("\n");

	printf("%o ..S...... (..s...... if +x)\n", S_ISUID);
	printf("%o .....S... (.....s... if +x)\n", S_ISGID);
	printf("%o ........T (........t if +x)\n", S_ISVTX);

	printf("\n");

	printf("%d\n", S_ISUID + S_ISGID);

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
	printf("%o ...rw-...\n", S_IRGRP + S_IWGRP);
	printf("%o ...r-x... (...r-s... if S_ISGID) ('*' with -F)\n", S_IRGRP + S_IXGRP);
	printf("%o ...r--...\n", S_IRGRP);
	printf("%o ...-wx... (...-ws... if S_ISGID) ('*' with -F)\n", S_IWGRP + S_IXGRP);
	printf("%o ...-w-...\n", S_IWGRP);
	printf("%o ...--x... (...--s... if S_ISGID) ('*' with -F)\n", S_IXGRP);

	printf("\n");

	printf("%o ......rwx (......rwt if S_ISVTX) ('*' with -F)\n", S_IRWXO);
	printf("%o ......rw-\n", S_IROTH + S_IWOTH);
	printf("%o ......r-x (......r-t if S_ISVTX) ('*' with -F)\n", S_IROTH + S_IXOTH);
	printf("%o ......r--\n", S_IROTH);
	printf("%o ......-wx (......-wt if S_ISVTX) ('*' with -F)\n", S_IWOTH + S_IXOTH);
	printf("%o ......-w-\n", S_IWOTH);
	printf("%o ......--x (......--t if S_ISVTX) ('*' with -F)\n", S_IXOTH);

	return (0);
}
