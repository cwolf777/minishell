/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/11 15:01:52 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




int main(void)
{
	char	*input;
	// char	*res;
	// t_list	*tokens;
	// char **ps;
	while (1)
	{
		input = read_prompt();
		// char **split = ft_split2(input, "\t\n\v\f\r ");
		// print_string_array(split);
		get_token(input);
		// append_node(&tokens, );
		// res = execute(input, envp);
		// free(input);
		// ft_printf("%s\n", res);
		// free(res);
	}
	rl_clear_history();

	return (EXIT_SUCCESS);
}
