/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:51:28 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/26 17:54:52 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 6) == 0)
		return (1);
	return (0);
}

void	mycd(t_cmd *cmd)
{
	t_exec_cmd *exec;
	char	*pwd;
	char	*new_pwd;

	exec = (t_exec_cmd *)cmd;
	if (ft_strncmp(exec->cmd_args[0], "cd", 3) != 0)
		return ;
	if (exec->cmd_args[1] == NULL)
		chdir(getenv("HOME"));
	else if (ft_strncmp(exec->cmd_args[1], "..", 3) == 0)
	{
		pwd = getcwd(NULL, 0);
		new_pwd = ft_strrchr(pwd, '/');
		if (!new_pwd)
			return ;
		*new_pwd = '\0';
		chdir(pwd);
	}
	else
	{
		chdir(exec->cmd_args[1]);
	}
}