/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:27:02 by msorin            #+#    #+#             */
/*   Updated: 2017/11/20 15:27:03 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//17000001
//385875969

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

# define C30 "\x1B[30m"
# define C31 "\x1B[31m"
# define C34 "\x1B[34m"
# define C35 "\x1B[35m"
# define C41 "\x1B[41m"
# define C42 "\x1B[42m"
# define C43 "\x1B[43m"
# define C46 "\x1B[46m"
# define RESETNDL "\033[0m\n"

# define k0 ""
// /Users/msorin/Desktop/gh_ft_ls/test/test_prot/check5.txt
# define k1 C35
// /Users/msorin/goinfre
# define k2 C34
// /Users/msorin/Desktop/gh_ft_ls/test/test_prot/test3
# define k3 C31
// /Users/msorin/Desktop/gh_ft_ls/test/test_prot/truc
# define k4 C46 C34
// /dev/disk1
# define k5 C43 C34
// /dev/rdisk1
# define k6 C41 C30
// /Users/msorin/Desktop/gh_ft_ls/test/test_prot/a.out
# define k7 C43  C30
// /Users/msorin/Desktop/gh_ft_ls/test/test_prot/test1
# define k8 C42 C30
// /Users/msorin/Desktop/gh_ft_ls/test/test_prot/test2

# define TAB(x) {write(1, (char*[]){k0, k1, k2, k3, k4, k5, k6, k7, k8}[x], 5 * ((x > 0) + (x > 3)));}

typedef struct stat	t_stat;

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

void	ft_putnbrhexa(size_t nb)
{
	char	c;
	char	ech[16] = "0123456789ABCDEF";

	if (!(nb / 16) && !(nb % 16))
	{
		write(1, "0", 1);
		return ;
	}
	if (nb / 16)
		ft_putnbrhexa(nb / 16);
	c = ech[nb % 16];
	write(1, &c, 1);
}

void ft_putnbr_octal(size_t t)
{
	char	c;

	if (t && (t / 8))
		ft_putnbr_octal((int)(t / 8));
	c = (t % 8) + '0';
	write(1, &c, 1);
}

void	ft_putnbrhexa_ndl(int nb)
{
	ft_putnbrhexa(nb);
	write(1, "\n", 1);
}

void	ft_putnbroct_ndl(int nb)
{
	ft_putnbr_octal(nb);
	write(1, "\n", 1);
}

int		main(void)
{
	char	c[9][60] =
	{
		"/Users/msorin/Desktop/gh_ft_ls/test/test_prot/check5.txt",
		"/Users/msorin/goinfre",
		"/Users/msorin/Desktop/gh_ft_ls/test/test_prot/test3",
		"/Users/msorin/Desktop/gh_ft_ls/test/test_prot/truc",
		"/dev/disk1",
		"/dev/rdisk1",
		"/Users/msorin/Desktop/gh_ft_ls/test/test_prot/a.out",
		"/Users/msorin/Desktop/gh_ft_ls/test/test_prot/test1",
		"/Users/msorin/Desktop/gh_ft_ls/test/test_prot/test2"
	};
	int		i;
	t_stat	*s;
	char	*str;

	s = malloc(sizeof(t_stat));
	i = 0;
	while (i < 9)
	{
		lstat(c[i], s);
		str = ft_strjoin_f("ls -dG ", c[i], 0);
		system(str);
		TAB(i);
		ft_putnbr_octal(s->st_mode);
		write(1, RESETNDL, 5);
		free(str);
		i++;
	}
	return 0;
}