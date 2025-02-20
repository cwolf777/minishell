/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:00:37 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/19 14:56:43 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	panic(char *error_msg)
{
	if (error_msg)
		ft_printf("%s",error_msg);
	exit(EXIT_FAILURE);
}

int	fork_plus()
{
	int	pid;

	pid = fork();
	if (pid < 0)
		panic("fork fail");
	return (pid);
}

char	*ft_char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	reset_standard_fds(int in, int out, int err)
{
	if (dup2(in, STDIN_FILENO) > 0)
		panic("reset stdin fail");
	if (dup2(out, STDOUT_FILENO) > 0)
		panic("reset stdout fail");
	if (dup2(err, STDERR_FILENO) > 0)
		panic("reset stderr fail");
	close(in);
	close(out);
	close(err);
}
