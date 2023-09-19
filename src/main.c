/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:13:09 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/19 20:39:03 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/minishell.h"
#include <unistd.h>

int	main(int ac, char **av, char **envp)
{
	char	*tmp;

	(void)av;
	(void)ac;
	while (1)
	{
		
		default_command(envp, tmp);
	}
	// printf("\n----------------------------------------\n\n");
	// while (*envp)
	// {
	// 	printf("%s\n", *envp);
	// 	envp++;
	// }
}
