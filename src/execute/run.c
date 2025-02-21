/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:49:13 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/21 12:44:16 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run(t_cmd *cmd, char *envp[])
{
	if (!cmd)
		return ;
	if (cmd->type == EXEC)
		run_exec((t_exec_cmd *)cmd, envp);
	if (cmd->type == PIPE)
		run_pipe((t_pipe_cmd *)cmd, envp);
	else if (cmd->type == REDIR)
		run_redir((t_redir_cmd *)cmd, envp);
	else if (cmd->type == SEQ)
		run_seq((t_seq_cmd *)cmd, envp);
	else if (cmd->type == BACK)
		run_back((t_back_cmd *)cmd, envp);
}

void	run_pipe(t_pipe_cmd *pipe_cmd, char *envp[])
{
	int	tunnel[2];

	if (pipe(tunnel) < 0)
		panic("pipe fail");
	if (fork_plus() == 0)
	{
		close(tunnel[0]);
		dup2(tunnel[1], STDOUT_FILENO);
		close(tunnel[1]);
		run(pipe_cmd->left, envp);
	}
	if (fork_plus() == 0)
	{
		close(tunnel[1]);
		dup2(tunnel[0], STDIN_FILENO);
		close(tunnel[0]);
		run(pipe_cmd->right, envp);
	}
	close(tunnel[0]);
	close(tunnel[1]);
	wait(NULL);
	wait(NULL);
}
void	run_back(t_back_cmd *back, char *envp[])
{
	if (fork_plus() == 0)
		run(back->left, envp);
	exit(EXIT_SUCCESS);
}

void	run_seq(t_seq_cmd *seq, char *envp[])
{
	if (fork_plus() == 0)
		run((t_cmd*)seq->left, envp);
	wait(NULL);
	run((t_cmd *)seq->right, envp);
}

void	run_redir(t_redir_cmd *redir, char *envp[])
{
	int	saved_in;
	int	saved_out;
	int	saved_err;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDERR_FILENO);
	saved_err = dup(STDOUT_FILENO);
	close(redir->fd);
	if (open(redir->file, redir->mode, 0644) < 0)
		panic("redir open failed");
	run(redir->cmd, envp);
	reset_standard_fds(saved_in, saved_out, saved_err);
}

