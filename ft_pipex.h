/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:50:57 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 19:46:40 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stddef.h>
# include "libft/libft.h"

//inside ft_pipex.c
void	ft_pipex(char **argv, char **envp);
void	ft_pid1(int fd1, int *piped, char *cmd1, char **envp);
void	ft_pid2(int fd2, int *piped, char *cmd2, char **envp);

//inside ft_execute.c
void	ft_exec(char **argv, char **envp);

//inside ft_utils.c
char	*ft_strcat(char *s1, const char *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_error(char *str);

#endif /* !FT_PIPEX_H */
