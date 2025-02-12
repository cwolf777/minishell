/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:10:15 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/12 13:42:10 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static char 	*parent(int pipe_fd[2]);
static void		child(int pipe_fd[2], char *prompt, char *envp[]);

char	*execute(char *prompt, char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;
	char	*res;

	res = "";
	pipe(pipe_fd);
	
	pid = fork();
	if (pid == 0)
		child(pipe_fd, prompt, envp);
	else
	{
		res = parent(pipe_fd);
		wait(NULL);
		return (res);
	}
	return (NULL);
}

static void	child(int pipe_fd[2], char *prompt, char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;

	close(pipe_fd[0]);
	cmd_args = ft_split(prompt, ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_str_arr(cmd_args);
		handle_error("command not found", 127);
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	execve(cmd_path, cmd_args, envp);
	free_str_arr(cmd_args);
	free(cmd_path);
	exit(EXIT_FAILURE);
}

static char 	*parent(int pipe_fd[2])
{
	char	*buffer;
	int		bytes_read;
	char	*result;
	char	*temp;

	close(pipe_fd[1]);
	buffer = malloc(sizeof(char) * 256);
	result = ft_strdup("");
	while((bytes_read = read(pipe_fd[0], buffer, 255)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(result, buffer);
		free(result);
		result = temp;
	}
	close(pipe_fd[0]);
	return (result);
}