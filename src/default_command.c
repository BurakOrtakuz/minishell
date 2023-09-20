/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:25:27 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/20 15:32:31 by bortakuz         ###   ########.fr       */
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

void	default_command(char **envp, char *data)
{
	char	**path;
	char	**variables;
	pid_t	pid;
	int		i;
	char	*tmp;
	int		ret;

	path = get_path(envp);
	variables = ft_split(data, ' ');
	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (path[i])
		{
			tmp = ft_strjoin(path[i], variables[0]);
			execve(tmp, &variables[0], envp);
			free(tmp);
			i++;
		}
	}
	else
	{
		waitpid(pid, &ret, 0);
	}
}
