/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:36:27 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 14:36:28 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <sys/xattr.h>
#include <sys/types.h>
#include <sys/acl.h>

static char	st_get_file_type(int mode)
{
	if ((mode & S_IFSOCK) == S_IFSOCK)
		return ('s');
	if ((mode & S_IFLNK) == S_IFLNK)
		return ('l');
	if ((mode & S_IFREG) && !(mode & S_IFBLK))
		return ('-');
	if ((mode & S_IFBLK) == S_IFBLK)
		return ('b');
	if ((mode & S_IFDIR) && !(mode & S_IFLNK))
		return ('d');
	if ((mode & S_IFCHR) && !(mode & S_IFSOCK))
		return ('c');
	if (mode & S_IFIFO)
		return ('p');
	return ('-');
}

static char	st_set_exe(int mode, int ugo)
{
	char	ret;

	if (!ugo)
	{
		if (mode & S_ISUID)
			ret = (mode & S_IXUSR) ? 's' : 'S';
		else
			ret = (mode & S_IXUSR) ? 'x' : '-';
	}
	if (ugo == -1)
	{
		if (mode & S_ISGID)
			ret = (mode & S_IXGRP) ? 's' : 'S';
		else
			ret = (mode & S_IXGRP) ? 'x' : '-';
	}
	if (ugo == 1)
	{
		if (mode & S_ISVTX)
			ret = (mode & S_IXOTH) ? 't' : 'T';
		else
			ret = (mode & S_IXOTH) ? 'x' : '-';
	}
	return (ret);
}

static char	st_spe_char(char *path)
{
	char	ret;
	acl_t	acl;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ret = '@';
	else
	{
		if ((acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)) != NULL)
		{
			ret = '+';
			acl_free(acl);
		}
		else
			ret = ' ';
	}
	return (ret);
}

char		*get_mode(char *str, int mode, char *path)
{
	char	cmod[12];
	char	*ret;

	cmod[0] = st_get_file_type(mode);
	cmod[1] = mode & S_IRUSR ? 'r' : '-';
	cmod[2] = mode & S_IWUSR ? 'w' : '-';
	cmod[3] = st_set_exe(mode, 0);
	cmod[4] = mode & S_IRGRP ? 'r' : '-';
	cmod[5] = mode & S_IWGRP ? 'w' : '-';
	cmod[6] = st_set_exe(mode, -1);
	cmod[7] = mode & S_IROTH ? 'r' : '-';
	cmod[8] = mode & S_IWOTH ? 'w' : '-';
	cmod[9] = st_set_exe(mode, 1);
	cmod[10] = st_spe_char(path);
	cmod[11] = '\0';
	ret = ft_strjoin_f(" ", str, 2);
	ret = ft_strjoin_f(cmod, ret, 2);
	return (ret);
}
