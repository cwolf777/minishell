/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:49:13 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/18 16:38:02 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run(t_cmd *cmd)
{
	int	pipe_fd[2];

	if (!cmd)
		panic("run cmd = NULL");
	else if (cmd->type = EXEC)
		run_exec((t_exec_cmd *)cmd);
	else if (cmd->type = REDIR)
		run_redir((t_redir_cmd *)cmd);
	else if (cmd->type = SEQ)
		run_seq((t_seq_cmd *)cmd);
	else if (cmd->type = BACK)
		run_back((t_back_cmd *)cmd);
}

void	run_pipe(t_pipe_cmd pipe_cmd)
{
	int	tunnel[2];

	if (pipe(tunnel[2]) < 0)
		panic("pipe fail");
	if (fork_plus() == 0)
	{
		close(tunnel[0]);
		dup2(tunnel[1], STDOUT_FILENO);
		close(STDOUT_FILENO);
		run(pipe_cmd.left);
	}
	if (fork_plus() == 0)
	{
		close(tunnel[1]);
		dup2(tunnel[0], STDIN_FILENO);
		close(STDIN_FILENO);
		run(pipe_cmd.right);
	}
	close(tunnel[0]);
	close(tunnel[1]);
	wait(NULL);
	wait(NULL);
}
void	run_back(t_back_cmd *back)
{
	if (fork_plus() == 0)
		run(back->left);
	exit(EXIT_SUCCESS);
}

void	run_seq(t_seq_cmd *seq)
{

	if (fork_plus() == 0)
		run((t_cmd*)seq->left);
	wait(NULL);
	run((t_cmd *)seq->right);
}

void	run_redir(t_redir_cmd *redir)
{
	close(redir->fd);
	if (open(redir->file, redir->mode) < 0)
		panic("redir open failed");
	run(redir->cmd);
}