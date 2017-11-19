/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:31:02 by msorin            #+#    #+#             */
/*   Updated: 2017/11/07 12:09:52 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

static int	ft_strlen(const char *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		return (i);
	}
	return (-1);
}

static char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

static void	ft_fill_strjoin(char *dest, char *src, size_t *i, size_t *j)
{
	if (src)
	{
		while (src[*j] != '\0')
		{
			dest[*i] = src[*j];
			*i = *i + 1;
			*j = *j + 1;
		}
	}
}

static char	*ft_strjoin_f(char *s1, char *s2, int f)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	j = 0;
	ft_fill_strjoin(str, (char *)s1, &i, &j);
	j = 0;
	ft_fill_strjoin(str, (char *)s2, &i, &j);
	str[i] = '\0';
	if (f & 1)
		free(s1);
	if (f & 2)
		free(s2);
	return (str);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		ret;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	if (!s2[i] && s1[i])
		ret = ((s1[i] - s2[i]) < 0) ? 1 : (s1[i] - s2[i]);
	else if (!s1[i] && s2[i])
		ret = ((s1[i] - s2[i]) > 0) ? -1 : (s1[i] - s2[i]);
	else
		ret = s1[i] - s2[i];
	return (ret);
}

static void	print_stat(t_stat *s)
{
	printf("s->st_dev - %d\t/* ID du périphérique contenant le fichier */\n", s->st_dev);
	printf("s->st_ino - %llu\t/* Numéro inœud */\n", s->st_ino);
	printf("s->st_mode - %o\t/* Protection */\n", s->st_mode);
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
	printf("\n");
}

int			new_read(const char *f_src)
{
	char	*f_new;
	DIR		*d;
	t_dir	*r;
	t_stat	*st;
	int		e;

	if (!(st = malloc(sizeof(t_stat))))
		return (1);
	if (!(d = opendir(f_src)))
	{
		perror(f_src);
		free(st);
		return (1);
	}
	e = 0;
	while ((r = readdir(d)))
	{
		f_new = ft_strjoin_f((char *)f_src, "/", 0);
		f_new = ft_strjoin_f(f_new, r->d_name, 1);
		if (lstat(f_new, st))
		{
			perror(f_new);
			printf("\n");
			e = 1;
		}
		else
		{
			printf("%s:\n", f_new);
			print_stat(st);
			if (ft_strcmp(r->d_name, ".") && ft_strcmp(r->d_name, "..") && (st->st_mode & S_IFDIR))
				e = new_read(f_new);
		}
		free(f_new);
	}
	free(st);
	return (e);
}

int			main(void)
{
	char	my_dir[128] = "/Users/msorin/Desktop/gh_ft_ls/test/test_prot";

	return (new_read(my_dir));
}
