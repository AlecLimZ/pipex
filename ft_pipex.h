/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:31:47 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 11:57:53 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H 

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

extern char	**environ;

//inside ft_pipex.c
void	ft_pipex(char *input, char *cm1, char *cmd2, char *output);
void	ft_pid1(int fd1, int *pipes, char *cmd1);
void	ft_pid2(int fd2, int *pipes, char *cmd2);

//inside ft_execute.c
void	ft_exec(char **argv);

//inside ft_utils.c
void	ft_error(char *s);
char	*ft_strcat(char *s1, const char *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);

#endif
