/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:51:18 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 19:46:27 by leng-chu         ###   ########.fr       */
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

char	**ft_get_path(char **envp)
{
	int			i;
	char		*p;
	char		**str;

	i = 0;
	str = NULL;
	while (envp[i])
	{
		if ((ft_strnequ(envp[i], "PATH", 4)) == 1)
		{
			p = envp[i];
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

void	ft_exec(char **argv, char **envp)
{
	char	**path;
	char	*buf;
	int		i;

	i = 0;
	path = ft_get_path(envp);
	while (path[i])
	{
		buf = ft_conc(path[i], argv[0]);
		if (execve(buf, argv, envp) != -1)
		{
			i = -34;
			break ;
		}
		else
			i++;
	}
	if (i >= 0)
		ft_error("Could not find command\n");
}
