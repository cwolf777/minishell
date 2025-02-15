/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:49:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/15 18:24:42 by phhofman         ###   ########.fr       */
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
	if (!*list)
		panic("syntax error, leftovers in prompt");
	return (cmd);
}
t_cmd	*parse_line(t_list **list)
{
	t_cmd	*cmd;
	t_token	*token;

	cmd = parse_pipe(list);
	token = (t_token *)(*list)->content;
	if (token->type == BACK)
	{
		cmd = back_cmd_init(cmd);
		*list = (*list)->next;
		token = (t_token *)(*list)->content;
	}
	if (token->type == SEQ)
	{
		*list = (*list)->next;
		cmd = seq_cmd_init(cmd, parse_line(list));
	}
	return (cmd);
}



t_cmd	*parse_pipe(t_list	**list)
{
	t_token *token;
	t_cmd	*pipe;
	t_cmd	*left;
	t_cmd	*right;
	right = NULL;
	left = NULL;

	if (!*list)
		return (NULL);
	token = (t_token *)(*list)->content;
	// print_tokens(*list);
	if (token->type == TEXT)
	{
		// *list = (*list)->next;
		left = parse_exec(list); // cat 
	}
	if (!*list)
		return (left);
	token = (t_token *)(*list)->content;
	if (token->type == PIPE)
	{
		*list = (*list)->next;
		right = parse_pipe(list); // echo + ls
	}
	
	pipe = pipe_cmd_init(left, right);
	// syntax check
	return ((t_cmd *)pipe);
}

t_cmd	*parse_exec(t_list **list)
{
	t_cmd	*exec;
	t_token *token;
	char **split;
	char	*join;

	token = (t_token *)(*list)->content;
	if (token == REDIR)
	{
		exec = parse_redir(list, parse_exec((*list)->next->next));
		return (exec);
	}
	join = ft_strdup("");
	while (*list)
	{
		token = (t_token *)(*list)->content;
		if (token->type != TEXT)
			break;
		join = ft_strjoin(join, token->value);
		join = ft_strjoin(join, " ");
		*list = (*list)->next;
	}
	split = ft_split2(join, "\t\n\v\f\r ");
	exec = exec_cmd_init(split); // ["cat", "-e", "Makefile"]
	if (token->type == REDIR)
	{
		exec = parse_redir(list, exec);
	}

	return (exec);
}

t_cmd	*parse_redir(t_list **list, t_exec_cmd *cmd)
{
	t_token		*token;
	t_redir_cmd	*redir;
	char		*redir_symbol;

	redir = NULL;
	token = (t_token *)(*list)->content;
	redir_symbol = token->value;
	*list = (*list)->next;
	token = (t_token *)(*list)->content;
	if (token->type != TEXT)
		panic("error redirect fail no file");
	if (ft_strncmp(redir_symbol, "<", 2) == 0)
	{
		redir = redir_cmd_init(cmd, token->value, STDIN_FILENO, O_RDONLY);
	}
	if (ft_strncmp(redir_symbol, ">", 2) == 0)
	{
		redir = redir_cmd_init(cmd, token->value, STDOUT_FILENO, O_WRONLY | O_CREAT | O_TRUNC);
	}
	if (ft_strncmp(redir_symbol, "+", 2) == 0)
	{
		// >>
		redir = redir_cmd_init(cmd, token->value, STDOUT_FILENO, O_WRONLY | O_CREAT);
	}
	*list = (*list)->next;
	return ((t_cmd *)redir);
} 