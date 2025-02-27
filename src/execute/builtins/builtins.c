/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:51:28 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/27 15:33:01 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_builtins(t_exec_cmd *cmd, char *envp[])
{
	char *builtin;
	int	len;

	(void)envp;
	builtin = cmd->cmd_args[0];
	len = ft_strlen(builtin);
	if (ft_strncmp(builtin, "cd", len) == 0)
		exec_cd(cmd);
	else if (ft_strncmp(builtin, "export", len) == 0)
		exec_export(cmd, envp);

}

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

void	exec_cd(t_exec_cmd *cmd)
{
	char	*pwd;
	char	*new_pwd;

	if (ft_strncmp(cmd->cmd_args[0], "cd", 3) != 0)
		return ;
	if (cmd->cmd_args[1] == NULL)
		chdir(getenv("HOME"));
	else if (ft_strncmp(cmd->cmd_args[1], "..", 3) == 0)
	{
		pwd = getcwd(NULL, 0);
		new_pwd = ft_strrchr(pwd, '/');
		if (!new_pwd)
			return ;
		*new_pwd = '\0';
		chdir(pwd);
	}
	else
		chdir(cmd->cmd_args[1]);
}

void	exec_export(t_exec_cmd *cmd, char *envp[])
{
	char	**entry;
	int		i;

	i = 1;
	while (cmd->cmd_args[i] != NULL)
	{
		entry = ft_split(cmd->cmd_args[i], '=');
		print_string_array(entry);
		add_env_var(&envp, entry[0], entry[1]);
		free_str_arr(entry);
		i++;
	}
	if (i == 1)
		print_string_array(envp);

}
