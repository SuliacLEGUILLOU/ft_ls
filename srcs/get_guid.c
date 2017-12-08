/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_guid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:50:47 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 11:51:08 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

char	*set_grp(gid_t gid)
{
	t_grp	*grp;

	grp = getgrgid(gid);
	return (ft_strdup(grp->gr_name));
}

char	*set_usr(uid_t uid)
{
	t_pass	*usr;

	usr = getpwuid(uid);
	return (ft_strdup(usr->pw_name));
}
