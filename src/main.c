/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/07 13:16:46 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(char **prompt)
{
	int i = 0;
	while (prompt[i] != NULL)
	{
		ft_printf("%s\n", prompt[i]);
		i++;
	}
}


int main(void)
{
	char	*input;
	// char	*res;
	
	while (1)
	{
		input = read_prompt();
		char **split = ft_split2(input, "\t\n\v\f\r ");
		create_cmd_args(split);
		// res = execute(input, envp);
		// free(input);
		// ft_printf("%s\n", res);
		// free(res);
	}
	rl_clear_history();

	return (EXIT_SUCCESS);
}
