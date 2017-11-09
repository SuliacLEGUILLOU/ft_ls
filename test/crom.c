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

static void	change_prot(char f[4], char l[4], char p[4])
{
	char	*touch;
	char	*ln;
	char	*chmod;

	touch = ft_strjoin_f("touch ", f, 0);
	system(touch);
	chmod = ft_strjoin_f("chmod ", p, 0);
	chmod = ft_strjoin_f(chmod, " ", 1);
	chmod = ft_strjoin_f(chmod, f, 1);
	system(chmod);
	ln = ft_strjoin_f("ln -s ", f, 0);
	ln = ft_strjoin_f(ln, " ", 1);
	ln = ft_strjoin_f(ln, l, 1);
	system(ln);
	free(touch);
	free(chmod);
	free(ln);
}

int			main(void)
{
	int		i;
	int		fd;
	int		max;
	char	file[4];
	char	link[4];
	char	prot[4];

	max = 8 * 8 * 8;
	i = 0;
	while (i < max)
	{
		file[0] = 'f';
		link[0] = 'l';
		file[1] = (((i / 8) / 8) % 8) + '0';
		link[1] = (((i / 8) / 8) % 8) + '0';
		prot[0] = (((i / 8) / 8) % 8) + '0';
		file[2] = ((i / 8) % 8) + '0';
		link[2] = ((i / 8) % 8) + '0';
		prot[1] = ((i / 8) % 8) + '0';
		file[3] = (i % 8) + '0';
		link[3] = (i % 8) + '0';
		prot[2] = (i % 8) + '0';
		prot[3] = ' ';
		change_prot(file, link, prot);
		i++;
	}
	return (0);
}
