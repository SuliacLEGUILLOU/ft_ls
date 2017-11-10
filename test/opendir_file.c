#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct dirent	t_dir;

static int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strnew(size_t len)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	return (ret);
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

int			main()
{
	char	dir[] = "/Users/msorin/Desktop/gh_ft_ls/";
	char	*str;
	DIR 	*d1;
	DIR		*d2;
	t_dir	*r;

	if (!(d1 = opendir(dir)))
		return (1);
	write(1, "\n", 1);
	while((r = readdir(d1)))
	{
		str = ft_strjoin_f(dir, r->d_name, 0);
		if(!(d2 = opendir(str)))
		{
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
			continue ;
		}
		closedir(d2);
		free(str);
	}
	closedir(d1);
	return (0);
}
