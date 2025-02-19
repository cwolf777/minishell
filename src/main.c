/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/19 09:54:45 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_prompt()
{
	char	*prompt;
	char	*input;
	
	prompt = "🤏🐚\033[0;32m $ \033[0m";

	input = readline(prompt);
	add_history(input);

	return (input);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*input;
	// char	*res;
	t_list	*list;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	(void)envp;
	g_in_child = 0;
	setup_signals();
	while (1)
	{
		input = read_prompt();
		if (!input)
		{
			ft_printf("exit");
			exit(EXIT_SUCCESS);
		}
		ft_printf("%s\n", input);
		list = tokenizer(input);
		if (list)
		{
			// ft_lstiter(list, print_tokens);
			cmd = parse_cmd(&list);
			// print_ast(cmd, 0);
			run(cmd, envp);
			
		}
		// res = execute(input, envp);
		free(input);
		// ft_printf("%s\n", res);
		// free(res);
	}
	rl_clear_history();

	return (EXIT_SUCCESS);
}
