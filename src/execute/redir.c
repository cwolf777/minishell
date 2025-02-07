/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:01 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/07 09:57:38 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir(t_redir redir)
{
	int	fd;

	fd = open(redir.file, redir.mode);
	if (fd < 0)
	{
		// todo: error handle;
		exit(EXIT_FAILURE);
	}
	if (redir.fd == STDOUT_FILENO)
		dup2(fd, STDOUT_FILENO);
	if (redir.fd == STDIN_FILENO)
		dup2(fd, STDIN_FILENO);
	close(fd);
}

void	redir_init(char *redir_symbol, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		exit(EXIT_FAILURE);
	redir->type = REDIR;
	redir->file = file;
	if (ft_strcmp(">",redir_symbol) == 0)
	{
		redir->fd = STDOUT_FILENO;
		redir->mode = O_WRONLY | O_CREAT | O_TRUNC | 0644;
	}
	if (ft_strcmp(">>", redir_symbol) == 0)
	{
		redir->fd = STDOUT_FILENO;
		redir->mode = O_WRONLY | O_CREAT | O_APPEND | 0644;
	}
	if (ft_strcmp("<", redir_symbol) == 0)
	{
		redir->fd = STDIN_FILENO;
		redir->mode = O_RDONLY;
	}
}
