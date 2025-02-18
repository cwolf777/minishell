/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/18 14:35:28 by cwolf            ###   ########.fr       */
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

int main(void)
{
	char	*input;
	// char	*res;
	t_list	*list;
	t_cmd	*cmd;
	g_in_child = 0;
	setup_signals();
	while (1)
	{
		input = read_prompt();
		ft_printf("%s\n", input);
		list = tokenizer(input);
		if (list)
		{
			// ft_lstiter(list, print_tokens);
			cmd = parse_cmd(&list);
			print_ast(cmd, 0);
			
		}
		// res = execute(input, envp);
		free(input);
		// ft_printf("%s\n", res);
		// free(res);
	}
	rl_clear_history();

	return (EXIT_SUCCESS);
}
