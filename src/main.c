/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:13:09 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/23 17:24:57 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/minishell.h"
#include <unistd.h>
#include "./libft/include/libft.h"

int	main(int ac, char **av, char **envp)
{
	(void)av;
	(void)ac;
	(void)envp;

	int		fd[2];
	
	if (pipe(fd) == -1)
	{
		return (1);
	}
	int	pid = fork();
	if(pid < 0)
	{
		return 2;
	}
	if(pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		default_command(envp, "ls");
	}
	int pid2= fork();
	if(pid2 < 0)
	{
		return 2;
	}
	if(pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		default_command(envp, "cat");
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);


	
	// while (1)
	// {
	// 	tmp = get_next_line(1);
	// 	tmp = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
	// 	default_command(envp, tmp);
	// 	free(tmp);
	// }
}
