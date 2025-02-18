/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:45:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/18 10:26:36 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_cmd_args(char *cmd, char *arg);

t_cmd	*parse_exec(t_list **list)
{
	t_cmd		*cmd;
	t_exec_cmd	*exec;
	t_token		*token;
	char		**cmd_args;
	char		*cmd_str;

	token = (t_token *)(*list)->content;
	if (token->type == PARENS)
		return (parse_block(list)); 
	cmd = exec_cmd_init(NULL);
	exec = (t_exec_cmd *)cmd;
	cmd = parse_redir(list, cmd);
	cmd_str = ft_strdup("");
	while (*list)
	{
		token = (t_token *)(*list)->content;
		if (token->type != TEXT)
			break;
		cmd_str = join_cmd_args(cmd_str, token->value);
		*list = (*list)->next;
		cmd = parse_redir(list, cmd);
	}
	cmd_args = ft_split2(cmd_str, "\t\n\v\f\r ");
	exec->cmd_args = cmd_args; // ["cat", "-e", "Makefile"]
	return (cmd);
}

static char	*join_cmd_args(char *cmd, char *arg)
{
	t_token	*token;
	char	*temp;

	temp = ft_strjoin(cmd, arg);
	free(cmd);
	cmd = ft_strjoin(temp, " ");
	free(temp);
	return (cmd);
}



