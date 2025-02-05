/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:51 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/05 16:33:13 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirect_child(int fd, int pipe_fd[2]);
static void	child(int pipe_fd[2], char *argv[], char *envp[]);
static int	redirect_parent(int fd, int pipe_fd[2]);
static void	parent(int pipe_fd[2], char *argv[], char *envp[]);

void	pipex(char *args[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		handle_error(NULL, EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		handle_error(NULL, EXIT_FAILURE);
	if (pid == 0)
		child(pipe_fd, args, envp);
	else
	{
		parent(pipe_fd, args, envp);
		wait(NULL);
	}
}

static void	child(int pipe_fd[2], char *argv[], char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;
	int		fd;

	close(pipe_fd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		handle_error(NULL, EXIT_FAILURE);
	cmd_args = ft_split(argv[2], ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_split(cmd_args);
		handle_error("command not found", 127);
	}
	if (redirect_child(fd, pipe_fd) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	execve(cmd_path, cmd_args, envp);
	free_split(cmd_args);
	free(cmd_path);
	exit(EXIT_FAILURE);
}

static int	redirect_child(int fd, int pipe_fd[2])
{
	if (dup2(fd, STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pipe_fd[1]);
	return (EXIT_SUCCESS);
}

static void	parent(int pipe_fd[2], char *argv[], char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;
	int		fd;

	close(pipe_fd[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		handle_error(NULL, EXIT_FAILURE);
	cmd_args = ft_split(argv[3], ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_split(cmd_args);
		handle_error("command not found", 127);
	}
	if (redirect_parent(fd, pipe_fd) == EXIT_FAILURE)
		handle_error(NULL, EXIT_FAILURE);
	execve(cmd_path, cmd_args, envp);
	free_split(cmd_args);
	free(cmd_path);
	handle_error(NULL, EXIT_FAILURE);
}

static int	redirect_parent(int fd, int pipe_fd[2])
{
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pipe_fd[0]);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}