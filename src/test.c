/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:00:44 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/07 14:21:51 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_cmd_args(char **prompt)
{
	int		i;
	int		start;
	int		len;
	char	**cmd_args;

	i = 0;
	start = 0;
	while (prompt[i] != NULL)
	{
		if (ft_strncmp(";", prompt[i], 1) == 0)
		{
			len = i - start;
			cmd_args = copy_split(prompt + start, len);
			cmd_init(cmd_args);
			print_prompt(cmd_args);
			start = i + 1;
		}
		i++;
	}
	return (prompt);
}

t_cmd	*cmd_init(char **cmd_args)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->type = CMD;
	cmd->cmd_args = cmd_args;
	return (cmd);
}

char	**copy_split(char **split, int len)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * len + 1);
	copy[len] = NULL;
	i = 0;
	while (i < len)
	{
		copy[i] = split[i];
		i++;
	}
	return (copy);
}
