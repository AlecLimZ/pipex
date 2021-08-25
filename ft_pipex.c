/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:50:20 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 18:12:24 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_pid1(int fd1, int *piped, char *cmd1)
{
	char	**command1;

	command1 = ft_split(cmd1, ' ');
	dup2(fd1, 0);
	dup2(piped[1], 1);
	close(fd1);
	close(piped[0]);
	close(piped[1]);
	if (command1[0][0] == '/')
	{
		if (execve(command1[0], command1, environ) == -1)
			ft_error("No such command, try removing the /\n");
	}
	else
		ft_exec(command1);
	close(fd1);
	close(piped[0]);
	close(piped[1]);
}

void	ft_pid2(int fd2, int *piped, char *cmd2)
{
	char	**command2;

	wait (NULL);
	command2 = ft_split(cmd2, ' ');
	dup2(piped[0], 0);
	dup2(fd2, 1);
	close(piped[0]);
	close(piped[1]);
	close(fd2);
	if (command2[0][0] == '/')
	{
		if (execve(command2[0], command2, environ) == -1)
			ft_error("No such command, try removing the /\n");
	}
	else
		ft_exec(command2);
	close(fd2);
	close(piped[0]);
	close(piped[1]);
}

void	ft_pipex(char *input, char *cmd1, char *cmd2, char *output)
{
	pid_t	pid;
	int		fd1;
	int		fd2;
	int		piped[2];

	pipe(piped);
	fd1 = open(input, O_RDONLY);
	fd2 = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd1 < 0 || fd2 < 0)
		ft_error("File open failure\n");
	pid = fork();
	if (pid == -1)
		ft_error("Process creation error \n");
	else if (pid == 0)
		ft_pid1(fd1, piped, cmd1);
	pid = fork();
	if (pid == -1)
		ft_error("Errror\n");
	else if (pid == 0)
		ft_pid2(fd2, piped, cmd2);
	close(fd1);
	close(fd2);
	close(piped[0]);
	close(piped[1]);
}
