/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/06 14:51:49 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	char	*input;
	char	*res;
	(void)argc;
	(void)argv;
	
	while (1)
	{
		input = read_prompt();
		char **split = ft_split_2(input, "\t\n\v\f\r ");
		res = execute(input, envp);
		free(input);
		ft_printf("%s\n", res);
		free(res);
	}
	rl_clear_history();

	return (EXIT_SUCCESS);
}
