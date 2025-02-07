/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:00:44 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/07 16:36:38 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_cmd_args(char **prompt)
{
	int		i;
	char	**cmd_args;
	int		len;

	i = 0;
	len = i;
	while (prompt[i] != NULL)
	{
		if (ft_strncmp(";", prompt[i], 1) == 0)
		{
			cmd_args = copy_split(prompt, i);
			return (cmd_args);
		}
		i++;
	}
	cmd_args = copy_split(prompt, i);
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

void	search_cmd(char **prompt)
{
	int		i;
	char	**cmd_args;

	i = 0;
	while (prompt[i] != NULL)
	{
		cmd_args = get_cmd_args(prompt);
		i++;
	}
}