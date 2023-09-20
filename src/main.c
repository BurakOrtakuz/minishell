/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:13:09 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/20 15:32:41 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/minishell.h"
#include <unistd.h>
#include "./libft/include/libft.h"

int	main(int ac, char **av, char **envp)
{
	char	*tmp;

	tmp = "asdfg";
	(void)av;
	(void)ac;
	(void)envp;
	while (1)
	{
		tmp = get_next_line(1);
		tmp = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		default_command(envp, tmp);
		free(tmp);
	}
	// printf("\n----------------------------------------\n\n");
	// while (*envp)
	// {
	// 	printf("%s\n", *envp);
	// 	envp++;
	// }
}
