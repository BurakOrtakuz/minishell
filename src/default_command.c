/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:25:27 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/21 18:39:54 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	**get_path(char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;

	i = -1;
	while (i++, envp[i])
	{
		if (!ft_strcontain(envp[i], "PATH="))
		{
			paths = ft_split(&envp[i][5], ':');
			i = -1;
			while (i++, paths[i])
			{
				tmp = ft_strjoin(paths[i], "/");
				free(paths[i]);
				paths[i] = tmp;
			}
			return (paths);
		}
	}
	return (NULL);
}

static void	run_execve(char *path, char **parameters, char **envp)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0)
	{
		execve(path, parameters, envp);
	}
	else
	{
		waitpid(pid, &ret, 0);
	}
}

void	default_command(char **envp, char *data)
{
	char	**path;
	char	**variables;
	int		i;
	char	*tmp;

	path = get_path(envp);
	variables = ft_split(data, ' ');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], variables[0]);
		if (access(tmp, X_OK) == 0)
		{
			run_execve(tmp, &variables[0], envp);
		}
		free(tmp);
		i++;
	}
}
