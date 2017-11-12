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

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>

typedef struct stat	t_stat;

int		main(void)
{
	t_stat	*s;

	s = NULL;
	s = malloc(sizeof(t_stat));
	printf("/Users/msorin/goinfre :\n");
	stat("/Users/msorin/goinfre", s);
	printf("stat :\n");
	if (s)
	{
		printf("s->st_dev - %d\t/* ID du périphérique contenant le fichier */\n", s->st_dev);
		printf("s->st_ino - %llu\t/* Numéro inœud */\n", s->st_ino);
		printf("s->st_mode - %d\t/* Protection */\n", s->st_mode);
		printf("s->st_nlink - %d\t/* Nb liens matériels */\n", s->st_nlink);
		printf("s->st_uid - %d\t/* UID propriétaire */\n", s->st_uid);
		printf("s->st_gid - %d\t/* GID propriétaire */\n", s->st_gid);
		printf("s->st_rdev - %d\t/* ID périphérique (si fichier spécial) */\n", s->st_rdev);
		printf("s->st_size - %lld\t/* Taille totale en octets */\n", s->st_size);
		printf("s->st_blksize - %d\t/* Taille de bloc pour E/S */\n", s->st_blksize);
		printf("s->st_blocks - %lld\t/* Nombre de blocs alloués */\n", s->st_blocks);
		printf("s->st_atime - %ld\t/* Heure dernier accès */ -> %s", s->st_atime, ctime(&(s->st_atime)));
		printf("s->st_mtime - %ld\t/* Heure dernière modification */ -> %s", s->st_mtime, ctime(&(s->st_mtime)));
		printf("s->st_ctime - %ld\t/* Heure dernier changement état */ -> %s", s->st_ctime, ctime(&(s->st_ctime)));
	}
	free(s);
	s = malloc(sizeof(t_stat));
	lstat("/Users/msorin/goinfre", s);
	printf("lstat :\n");
	if (s)
	{
		printf("s->st_dev - %d\t/* ID du périphérique contenant le fichier */\n", s->st_dev);
		printf("s->st_ino - %llu\t/* Numéro inœud */\n", s->st_ino);
		printf("s->st_mode - %d\t/* Protection */\n", s->st_mode);
		printf("s->st_nlink - %d\t/* Nb liens matériels */\n", s->st_nlink);
		printf("s->st_uid - %d\t/* UID propriétaire */\n", s->st_uid);
		printf("s->st_gid - %d\t/* GID propriétaire */\n", s->st_gid);
		printf("s->st_rdev - %d\t/* ID périphérique (si fichier spécial) */\n", s->st_rdev);
		printf("s->st_size - %lld\t/* Taille totale en octets */\n", s->st_size);
		printf("s->st_blksize - %d\t/* Taille de bloc pour E/S */\n", s->st_blksize);
		printf("s->st_blocks - %lld\t/* Nombre de blocs alloués */\n", s->st_blocks);
		printf("s->st_atime - %ld\t/* Heure dernier accès */ -> %s", s->st_atime, ctime(&(s->st_atime)));
		printf("s->st_mtime - %ld\t/* Heure dernière modification */ -> %s", s->st_mtime, ctime(&(s->st_mtime)));
		printf("s->st_ctime - %ld\t/* Heure dernier changement état */ -> %s", s->st_ctime, ctime(&(s->st_ctime)));
	}
	free(s);
	printf("\n");
	s = malloc(sizeof(t_stat));
	printf("/Volumes/Storage/goinfre/msorin :\n");
	stat("/Volumes/Storage/goinfre/msorin", s);
	printf("stat :\n");
	if (s)
	{
		printf("s->st_dev - %d\t/* ID du périphérique contenant le fichier */\n", s->st_dev);
		printf("s->st_ino - %llu\t/* Numéro inœud */\n", s->st_ino);
		printf("s->st_mode - %d\t/* Protection */\n", s->st_mode);
		printf("s->st_nlink - %d\t/* Nb liens matériels */\n", s->st_nlink);
		printf("s->st_uid - %d\t/* UID propriétaire */\n", s->st_uid);
		printf("s->st_gid - %d\t/* GID propriétaire */\n", s->st_gid);
		printf("s->st_rdev - %d\t/* ID périphérique (si fichier spécial) */\n", s->st_rdev);
		printf("s->st_size - %lld\t/* Taille totale en octets */\n", s->st_size);
		printf("s->st_blksize - %d\t/* Taille de bloc pour E/S */\n", s->st_blksize);
		printf("s->st_blocks - %lld\t/* Nombre de blocs alloués */\n", s->st_blocks);
		printf("s->st_atime - %ld\t/* Heure dernier accès */ -> %s", s->st_atime, ctime(&(s->st_atime)));
		printf("s->st_mtime - %ld\t/* Heure dernière modification */ -> %s", s->st_mtime, ctime(&(s->st_mtime)));
		printf("s->st_ctime - %ld\t/* Heure dernier changement état */ -> %s", s->st_ctime, ctime(&(s->st_ctime)));
	}
	free(s);
	s = malloc(sizeof(t_stat));
	lstat("/Volumes/Storage/goinfre/msorin", s);
	printf("lstat :\n");
	if (s)
	{
		printf("s->st_dev - %d\t/* ID du périphérique contenant le fichier */\n", s->st_dev);
		printf("s->st_ino - %llu\t/* Numéro inœud */\n", s->st_ino);
		printf("s->st_mode - %d\t/* Protection */\n", s->st_mode);
		printf("s->st_nlink - %d\t/* Nb liens matériels */\n", s->st_nlink);
		printf("s->st_uid - %d\t/* UID propriétaire */\n", s->st_uid);
		printf("s->st_gid - %d\t/* GID propriétaire */\n", s->st_gid);
		printf("s->st_rdev - %d\t/* ID périphérique (si fichier spécial) */\n", s->st_rdev);
		printf("s->st_size - %lld\t/* Taille totale en octets */\n", s->st_size);
		printf("s->st_blksize - %d\t/* Taille de bloc pour E/S */\n", s->st_blksize);
		printf("s->st_blocks - %lld\t/* Nombre de blocs alloués */\n", s->st_blocks);
		printf("s->st_atime - %ld\t/* Heure dernier accès */ -> %s", s->st_atime, ctime(&(s->st_atime)));
		printf("s->st_mtime - %ld\t/* Heure dernière modification */ -> %s", s->st_mtime, ctime(&(s->st_mtime)));
		printf("s->st_ctime - %ld\t/* Heure dernier changement état */ -> %s", s->st_ctime, ctime(&(s->st_ctime)));
	}
	free(s);
	return (0);
}
