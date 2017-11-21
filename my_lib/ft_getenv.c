/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:18:22 by msorin            #+#    #+#             */
/*   Updated: 2017/11/16 16:19:31 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_getenv(const char *val, const char **env)
{
	int	i;
	int	len;

	if (!val || !env || !(*env))
		return (NULL);
	len = ft_strlen(val);
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], val, len))
			return (ft_strdup((char *)(env[i] + len)));
	}
	return (NULL);
}
