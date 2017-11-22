/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:09:08 by msorin            #+#    #+#             */
/*   Updated: 2017/11/19 16:09:09 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct stat	t_stat;

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

static void	print_stat(const char *str, t_stat *s)
{
	char	*sys;

	printf("\n");
	printf("%s\n", str);
	sys = ft_strjoin_f("ls -l ", (char *)str, 0);
	system(sys);
	free(sys);
	printf("\n");
	printf("s->st_rdev - %x\t/* ID périphérique (si fichier spécial) */\n", s->st_rdev);
}

int			main(void)
{
	char	csp19[8][128] =
	{
		"/dev/cu.Boseorosteg-SPPDev-1",
		"/dev/tty.Boseorosteg-SPPDev-1",
		"/dev/cu.Bluetooth-Incoming-Port",
		"/dev/tty.Bluetooth-Incoming-Port",
		"/dev/cu.AirPodsdeClement-Wirele",
		"/dev/tty.AirPodsdeClement-Wirele",
		"/dev/cu.Boseorosteg-SPPDev",
		"/dev/tty.Boseorosteg-SPPDev"
	};
	char	csp_1[9][128] =
	{
		"/dev/bpf1",
		"/dev/cu.Boseorosteg-SPPDev",
		"/dev/afsc_type5",
		"/dev/ttys001",
		"/dev/urandom",
		"/dev/pfm",
		"/dev/ptyp1",
		"/dev/ttyp1",
		"/dev/rdisk0s1"
	};

	t_stat	*s;
	int		i;

	s = malloc(sizeof(t_stat));
	i = 0;
	while (i < 8)
	{
		if (lstat(csp19[i], s))
			perror(csp19[i]);
		else
			print_stat(csp19[i], s);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (lstat(csp_1[i], s))
			perror(csp_1[i]);
		else
			print_stat(csp_1[i], s);
		i++;
	}
	if (lstat("/dev/sdt", s))
		perror("/dev/sdt");
	else
		print_stat("/dev/sdt", s);
	if (lstat("/dev/autofs_control", s))
		perror("/dev/autofs_control");
	else
		print_stat("/dev/autofs_control", s);
	if (lstat("/dev/ptywf", s))
		perror("/dev/ptywf");
	else
		print_stat("/dev/ptywf", s);
	free(s);
	return 0;
}