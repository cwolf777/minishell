/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:57:25 by phhofman          #+#    #+#             */
/*   Updated: 2025/03/05 14:45:31 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*exec_cmd_init(char **cmd_args) //done
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *)gc_alloc(sizeof(t_exec_cmd));
	if (!exec_cmd)
		panic("malloc fail in exec init \n");
	exec_cmd->type = EXEC;
	exec_cmd->cmd_args = cmd_args;
	return ((t_cmd *)exec_cmd);
}
t_cmd	*redir_cmd_init(t_cmd *cmd, char *file, int fd, int mode) //done
{
	t_redir_cmd	*redir_cmd;

	redir_cmd = (t_redir_cmd *)gc_alloc(sizeof(t_redir_cmd));
	if (!redir_cmd)
		panic("malloc fail in redir init \n");
	redir_cmd->type = REDIR;
	redir_cmd->cmd = cmd;
	redir_cmd->file = file;
	redir_cmd->fd = fd;
	redir_cmd->mode = mode;
	return ((t_cmd *)redir_cmd);
}

t_cmd	*heredoc_cmd_init(t_cmd *cmd, char *value) //done
{
	t_heredoc_cmd	*heredoc_cmd;

	heredoc_cmd = (t_heredoc_cmd *)gc_alloc(sizeof(t_heredoc_cmd));
	heredoc_cmd->type = HERE_DOC;
	heredoc_cmd->cmd = cmd;
	heredoc_cmd->value = value;
	return ((t_cmd *)heredoc_cmd);
}

t_cmd	*pipe_cmd_init(t_cmd *left, t_cmd *right) //done
{
	t_pipe_cmd	*pipe_cmd;

	pipe_cmd = (t_pipe_cmd *)gc_alloc(sizeof(t_pipe_cmd));
	if (!pipe_cmd)
		panic("malloc fail in pipe init \n");
	pipe_cmd->type = PIPE;
	pipe_cmd->left = left;
	pipe_cmd->right = right;
	return ((t_cmd *)pipe_cmd);
}
t_cmd	*seq_cmd_init(t_cmd *left, t_cmd *right) //done
{
	t_seq_cmd	*seq_cmd;

	seq_cmd = (t_seq_cmd *)gc_alloc(sizeof(t_seq_cmd));
	if (!seq_cmd)
		panic("malloc fail in seq init \n");
	seq_cmd->type = SEQ;
	seq_cmd->left = left;
	seq_cmd->right = right;
	return ((t_cmd *)seq_cmd);
}

t_cmd	*back_cmd_init(t_cmd *left) // done
{
	t_back_cmd	*back_cmd;

	back_cmd = (t_back_cmd *)gc_alloc(sizeof(t_back_cmd));
	if (!back_cmd)
		panic("malloc fail in back init \n");
	back_cmd->type = BACK;
	back_cmd->left = left;
	return ((t_cmd *)back_cmd);
}

