/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/13 11:51:30 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char* argv[], char *envp[])
{
	char	*input;
	(void)argc;
	(void)argv;
	g_in_child = 0;
	setup_signals();
	char	*res;
	// t_list	*tokens;
	// char **ps;
	while (1)
	{
		input = read_prompt();
		if (!input) // STRG+D erkannt (EOF)
        {
            printf("exit\n");
            exit(0);
        }
		// char **split = ft_split2(input, "\t\n\v\f\r ");
		// print_string_array(split);
		get_token(input);
		// append_node(&tokens, );
		res = execute(input, envp);
		free(input);
		ft_printf("%s\n", res);
		free(res);
	}
	rl_clear_history();

	return (EXIT_SUCCESS);
}
