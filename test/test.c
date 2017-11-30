/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:36:36 by msorin            #+#    #+#             */
/*   Updated: 2017/11/02 11:06:58 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

int			ft_strlen(const char *s)
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

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*str;

	if ((size = ft_strlen(s1)) == -1)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	is1;
	unsigned int	is2;
	unsigned int	count;

	if (*s2 == 0 || s2 == NULL)
		return ((char *)s1);
	is1 = 0;
	is2 = 0;
	while (s1[is1] != '\0' && is1 < n)
	{
		count = is1;
		while (s1[is1] == s2[is2] && s1[is1] != '\0' && is1 < n)
		{
			if (s2[is2 + 1] == '\0')
				return ((char *)(s1 + count));
			is1++;
			is2++;
		}
		is2 = 0;
		is1 = count + 1;
	}
	return (NULL);
}

char	*ft_strnew(size_t size)
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

static void		ft_fill_strjoin(char *dest, char *src, size_t *i, size_t *j)
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

char			*ft_strjoin_f(char *s1, char *s2, int f)
{
	size_t		i;
	size_t		j;
	char		*str;

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

char		*ft_getenv(const char *val, char **env)
{
	int		i;
	int		len;
	char	*str;

	if (!val || !env || !(*env))
		return (NULL);
	len = ft_strlen(val);
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], val, len))
			return (ft_strdup((char *)(env[i] + len + 1)));
	}
	return (NULL);
}

void ft_putnbr_octal(int n)
{
	size_t	t;
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		t = -n;
	}
	else
		t = n;
	if (t && (t / 8))
		ft_putnbr_octal((int)(t / 8));
	c = (t % 8) + '0';
	write(1, &c, 1);
}

void ft_putnbr(int n)
{
	size_t	t;
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		t = -n;
	}
	else
		t = n;
	if (t && (t / 10))
		ft_putnbr((int)(t / 10));
	c = (t % 10) + '0';
	write(1, &c, 1);
}

	// int c;
	// write(1, "s->st_mode - ", 13);
	// c = s->st_mode;
	// ft_putnbr_octal(c);
	// write(1, "\n", 1);
	// ft_putnbr(c);
	// write(1, "\t/* Protection */\n", 18);

void print_stat (t_stat *s)
{
	// printf("s->st_dev - %d\t/* ID du périphérique contenant le fichier */\n", s->st_dev);
	// printf("s->st_ino - %llu\t/* Numéro inœud */\n", s->st_ino);
	// printf("s->st_mode - %o\t/* Protection */\n", s->st_mode);
	// printf("s->st_nlink - %d\t/* Nb liens matériels */\n", s->st_nlink);
	// printf("s->st_uid - %d\t/* UID propriétaire */\n", s->st_uid);
	// printf("s->st_gid - %d\t/* GID propriétaire */\n", s->st_gid);
	// printf("s->st_rdev - %d\t/* ID périphérique (si fichier spécial) */\n", s->st_rdev);
	// printf("s->st_size - %lld\t/* Taille totale en octets */\n", s->st_size);
	// printf("s->st_blksize - %d\t/* Taille de bloc pour E/S */\n", s->st_blksize);
	// printf("s->st_blocks - %lld\t/* Nombre de blocs alloués */\n", s->st_blocks);
	printf("s->st_atime - %ld\t/* Heure dernier accès */ -> %s", s->st_atime, ctime(&(s->st_atime)));
	printf("s->st_mtime - %ld\t/* Heure dernière modification */ -> %s", s->st_mtime, ctime(&(s->st_mtime)));
	printf("s->st_ctime - %ld\t/* Heure dernier changement état */ -> %s", s->st_ctime, ctime(&(s->st_ctime)));
};

void	print_ls(char *src)
{
	char	*dest;

	dest = ft_strjoin_f("ls -dla ", src, 0);
	system(dest);
	free(dest);
}

int	main(int ac, char **av, char **env)
{
	DIR		*d;
	t_dir	*r;
	t_stat	*s1;
	t_stat	*s2;
	char	*str;
	char	dir[100] = "/Users/msorin/Desktop/gh_ft_ls";
	//char	dir[32] = "/dev";
	t_stat	test;

	(void)test;
	s1 = malloc(sizeof(t_stat));
	s2 = malloc(sizeof(t_stat));
	d = opendir(dir);
	while ((r = readdir(d)))
	{
		str = ft_strjoin_f(ft_strjoin_f(dir, "/", 0), r->d_name, 1);
		write(1, str, ft_strlen(str));
		write(1, " :\n", 3);
		s1 = malloc(sizeof(t_stat));
		s2 = malloc(sizeof(t_stat));
		if (stat(str, s1)) //if (stat(dir, s1))
			perror("fail");
		else
		{
			write(1, "stat : ", 7);
			print_stat(s1);
		}
		if (lstat(str, s2)) //if (lstat(dir, s2))
			perror("arfl");
		else
		{
			write(1, "lstat : ", 8);
			print_stat(s2);
		}
//		print_ls(dir);
		print_ls(str);
		free(s1);
		free(s2);
		free(str);
	}
	closedir(d);
	return (0);
}
