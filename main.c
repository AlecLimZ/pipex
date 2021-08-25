/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:02:04 by leng-chu          #+#    #+#             */
/*   Updated: 2021/08/25 16:53:12 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
		ft_error_handling("Please type like: ./pipex file1 cmd1 cmd2 file2\n");
	else
		ft_pipex(argv[1], argv[2], argv[3], argv[4]);
	return (0);
}
