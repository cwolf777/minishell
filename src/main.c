/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/31 17:43:11 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	char	*pwd;
	char	*res;
	(void)argc;
	(void)argv;
	pwd = execute("pwd",envp);
	pwd = ft_strtrim(pwd, "\n");
	pwd = ft_strjoin(pwd," % ");
	while (1)
	{
		
		prompt = readline(pwd);
		res = execute(prompt, envp);
		ft_printf("%s", res);
	}

	return (EXIT_SUCCESS);
}