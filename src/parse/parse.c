/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:49:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/14 17:08:20 by phhofman         ###   ########.fr       */
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
		cmd = pipe->right;
		print_baum(cmd);
	}
}

t_cmd	*parse_pipe(t_list	**liste)
{
	t_token *token;
	t_cmd	*pipe;
	t_cmd	*left;
	t_cmd	*right;
	right = NULL;
	left = NULL;

	if (!*liste)
		return (NULL);
	token = (t_token *)(*liste)->content;
	print_tokens(*liste);
	if (token->type == TEXT)
	{
		left = parse_exec(liste); // cat 
		*liste = (*liste)->next;
	}
	if (!*liste)
		return (left);
	token = (t_token *)(*liste)->content;
	if (token->type == PIPE)
	{
		*liste = (*liste)->next;
		right = parse_pipe(liste); // echo + ls
	}
	
	pipe = pipe_cmd_init(left, right);
	// syntax check
	return ((t_cmd *)pipe);
}

t_cmd	*parse_exec(t_list **liste)
{
	t_cmd	*exec;
	t_token *token;

	char **split;

	token = (t_token *)(*liste)->content;
	split = ft_split2(token->value, "\t\n\v\f\r ");
	exec = exec_cmd_init(split);
	return (exec);
}