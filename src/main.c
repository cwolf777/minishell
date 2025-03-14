/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/26 10:30:18 by cwolf            ###   ########.fr       */
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
	t_list	*list;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	g_pid = 0;
	setup_signals();
	while (1)
	{
		input = read_prompt();
		if (!input)
		{
			ft_printf("exit");
			exit(EXIT_SUCCESS);
		}
		list = tokenizer(input);
		if (list)
		{
			// ft_lstiter(list, print_tokens);
			cmd = parse_cmd(&list);
			// print_ast(cmd, 0);
			if (fork_plus() == 0)
			{
				run(cmd, envp);
				exit(EXIT_SUCCESS);
			}
			wait(NULL);
			g_pid = 0;
		}
		free(input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
