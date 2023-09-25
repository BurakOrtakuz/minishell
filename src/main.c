/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:13:09 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/25 16:57:13 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "../inc/minishell.h"
#include <unistd.h>
#include <fcntl.h>
#include "./libft/include/libft.h"

int	main(int ac, char **av, char **envp)
{
	(void)av;
	(void)ac;
	(void)envp;

	int		fd[2];
	// char	*tmp;
	if (pipe(fd) == -1)
	{
		return (1);
	}
	// dup2(fd[1], 1);
	// // dup2(fd[0], 0);
	// // close(fd[0]);
	// // fcntl(fd[0], F_SETFL, O_NONBLOCK);
	// default_command(envp, "ls");
	// close(fd[1]);
	// tmp = get_next_line(fd[0]);

	// write(0, tmp, 66);
	// write(2, "asd", 3);
	// close(fd[0]);
	// default_command(envp, "cat");
    // read pipe */
	// fprintf(stderr,"aa\n%s\naa", tmp);
	int a = 4;
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
		exit(1);
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
		exit(1);
	}
	// close(fd[0]);
	// close(fd[1]);
	printf("%d", a);
	fflush(stdout);
		
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
