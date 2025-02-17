/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:49:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:32 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_baum(t_cmd *baum)
{
	if (baum->type == EXEC)
	{
		t_exec_cmd	*exec = (t_exec_cmd *)baum;
		print_string_array(exec->cmd_args);
	}
	if (baum->type == PIPE)
	{
		t_pipe_cmd	*pipe = (t_pipe_cmd *)baum;
		t_cmd	*cmd = pipe->left;
		print_baum(cmd);
		ft_printf(" | ");
		cmd = pipe->right;
		print_baum(cmd);
		ft_printf("\n");
	}
}
t_cmd	*parse_cmd(t_list **list)
{
	t_cmd	*cmd;

	cmd = parse_line(list);
	if (*list != NULL)
		panic("syntax error, leftovers in prompt");
	return (cmd);
}
t_cmd	*parse_line(t_list **list)
{
	t_cmd	*cmd;
	t_token	*token;

	cmd = parse_pipe(list);
	if (!*list)
		return (cmd);
	token = (t_token *)(*list)->content;
	if (token->type == BACK)
	{
		*list = (*list)->next;
		cmd = back_cmd_init(cmd);
		if (*list)
			cmd = seq_cmd_init(cmd, parse_line(list));
	}
	else if (token->type == SEQ)
	{
		*list = (*list)->next; // maybe to much can cause error
		cmd = seq_cmd_init(cmd, parse_line(list));
	}
	return (cmd);
}

t_cmd	*parse_block(t_list **list)
{
	t_cmd	*cmd;
	t_token	*token;

	token = (t_token *)(*list)->content;
	if (ft_strncmp("(", token->value, 2) != 0)
		panic("parse_block error");
	*list = (*list)->next;
	cmd = parse_line(list);
	token = (t_token *)(*list)->content;
	if (ft_strncmp(")", token->value, 2) != 0)
		panic("syntax error missing ')'");
	*list = (*list)->next;
	cmd = parse_redir(list, cmd);
	return (cmd);
}

t_cmd	*parse_pipe(t_list	**list)
{
	t_token *token;
	t_cmd	*cmd;

	cmd = parse_exec(list);
	if (!*list)
		return (cmd);
	token = (t_token *)(*list)->content;
	if (token->type == PIPE)
	{
		*list = (*list)->next;
		cmd = pipe_cmd_init(cmd, parse_pipe(list));	// echo | ls
	}
	return (cmd);
}

t_cmd	*parse_exec(t_list **list)
{
	t_cmd		*cmd;
	t_exec_cmd	*exec;
	t_token		*token;
	char		**split;
	char		*join;

	token = (t_token *)(*list)->content;
	if (token->type == PARENS)
		return (parse_block(list)); 
	cmd = exec_cmd_init(NULL);
	exec = (t_exec_cmd *)cmd;
	cmd = parse_redir(list, cmd);
	join = ft_strdup("");
	while (*list)
	{
		token = (t_token *)(*list)->content;
		if (token->type != TEXT)
			break;
		join = ft_strjoin(join, token->value);
		join = ft_strjoin(join, " ");
		*list = (*list)->next;
		cmd = parse_redir(list, cmd);
	}
	split = ft_split2(join, "\t\n\v\f\r ");
	exec->cmd_args = split; // ["cat", "-e", "Makefile"]
	return (cmd);
}

t_cmd	*parse_redir(t_list **list, t_cmd *cmd)
{
	t_token		*token;
	char		*redir_symbol;

	if (!*list)
		return (cmd);
	token = (t_token *)(*list)->content;
	if (token->type != REDIR)
		return (cmd);
	redir_symbol = token->value;
	*list = (*list)->next;
	token = (t_token *)(*list)->content;
	if (token->type != TEXT)
		panic("error redirect fail no file");
	if (ft_strncmp(redir_symbol, "<", 2) == 0)
		cmd = redir_cmd_init(cmd, token->value, STDIN_FILENO, O_RDONLY);
	if (ft_strncmp(redir_symbol, ">", 2) == 0)
		cmd = redir_cmd_init(cmd, token->value, STDOUT_FILENO, O_WRONLY | O_CREAT | O_TRUNC);
	if (ft_strncmp(redir_symbol, "+", 2) == 0)
		cmd = redir_cmd_init(cmd, token->value, STDOUT_FILENO, O_WRONLY | O_CREAT);
	*list = (*list)->next;
	return (cmd);
}
