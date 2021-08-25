/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:50:14 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 12:00:35 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	_exit(1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] != '\0' && --n)
		{
			if (ft_isalpha(s1[i]) && ft_isalpha(s2[i]))
			{
				if (ft_tolower(s1[i] != ft_tolower(s2[i])))
					return (0);
			}
			else if (s2[i] == '\0')
				return (0);
			++i;
		}
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}
