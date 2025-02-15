/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:49:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/15 16:23:24 by phhofman         ###   ########.fr       */
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
	// print_tokens(*liste);
	if (token->type == TEXT)
	{
		// *liste = (*liste)->next;
		left = parse_exec(liste); // cat 
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
	char	*join;
	// t_cmd	*redir;

	token = (t_token *)(*liste)->content;
	// if (token->type == REDIR)
	// {
	// 	liste = liste->next;
		
	// }
	join = ft_strdup("");
	// print_tokens(*liste);
	while (*liste)
	{
		token = (t_token *)(*liste)->content;
		if (token->type != TEXT)
			break;
		join = ft_strjoin(join, token->value);
		join = ft_strjoin(join, " ");
		*liste = (*liste)->next;
	}
	if (token->type == REDIR)
	{
		parse_redir(liste);
	}
	split = ft_split2(join, "\t\n\v\f\r ");
	exec = exec_cmd_init(split); // ["cat", "-e", "Makefile"]
	// redir = parse_exec(liste); 
	// redir_cmd_init(exec, )
	return (exec);
}

t_cmd	*parse_redir(t_list **liste)
{
	t_token *token;
	t_redir	*redir;

	token = (t_token *)(*liste)->content;
	if (ft_strncmp(token->value, "<", 2) == 0)
	{
		
	}
}