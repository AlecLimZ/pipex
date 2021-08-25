/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:51:18 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 17:01:18 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_conc(char *str, char *filename)
{
	char	*buf;

	buf = (char *)malloc(ft_strlen(str) + ft_strlen(filename) + 16);
	ft_strcat(buf, str);
	ft_strcat(buf, "/");
	ft_strcat(buf, filename);
	return (buf);
}

char	**ft_get_path(void)
{
	int			i;
	char		*p;
	char		**str;

	i = 0;
	str = NULL;
	while (environ[i])
	{
		if ((ft_strnequ(environ[i], "PATH", 4)) == 1)
		{
			p = environ[i];
			p += 5;
			str = ft_split(p, ':');
			i = -34;
			break ;
		}
		else
			i++;
	}
	return (str);
}

void	ft_exec(char **argv)
{
	char	**path;
	char	*buf;
	int		i;

	i = 0;
	path = ft_get_path();
	while (path[i])
	{
		buf = ft_conc(path[i], argv[0]);
		if (execve(buf, argv, environ) != -1)
		{
			i = -34;
			break ;
		}
		else
			i++;
	}
	if (i >= 0)
		ft_error_handling("Could not find command\n");
}
