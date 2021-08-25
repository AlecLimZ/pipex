/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:03:05 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 10:55:19 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_pid1(int fd0, int *pipes, char *cmd1)
{
	char	**command1;

	command1 = ft_split(cmd1, ' ');
	dup2(fd0, 0);
	dup2(pipes[1], 1);
	close(fd0);
	close(pipes[0]);
	close(pipes[1]);
	if (command1[0][0] == '/')
	{
		if (execve(command1[0], command1, environ) == -1)
			ft_error("Command does not exist.");
	}
	else
		ft_exec(command1);
	close(fd0);
	close(pipes[0]);
	close(pipes[1]);
}

void	ft_pid2(int fd1, int *pipes, char *cmd2)
{
	char	**command2;

	command2 = ft_split(cmd2, ' ');
	dup2(pipes[0], 0);
	dup2(fd1, 1);
	close(pipes[0]);
	close(pipes[1]);
	close(fd1);
	if (command2[0][0] == '/')
	{
		if (execve(command2[0], command2, environ) == -1)
			ft_error("Command does not exist.");
	}
	else
		ft_exec(command2);
	close(fd1);
	close(pipes[0]);
	close(pipes[1]);
}

void	ft_pipex(char *input, char *cmd1, char *cmd2, char *output)
{
	pid_t	pid;
	int		fd0;
	int		fd1;
	int		pipes[2];

	pipe(pipes);
	fd0 = open(input, O_RDONLY);
	fd1 = open(output, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd0 < 0 || fd1 < 0)
		ft_error("Failed open file");
	pid = fork();
	if (pid == -1)
		ft_error("Error creating process");
	else if (pid == 0)
		ft_pid1(fd0, pipes, cmd1);
	pid = fork();
	if (pid == -1)
		ft_error("Error creating process");
	else if (pid == 0)
		ft_pid1(fd1, pipes, cmd2);
	close(fd0);
	close(fd1);
	close(pipes[0]);
	close(pipes[1]);
}
