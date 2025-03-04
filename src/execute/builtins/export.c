/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:40:51 by phhofman          #+#    #+#             */
/*   Updated: 2025/03/04 10:21:06 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_env_entry(char **envp[],char *key, char *entry)
{
	int	i;

	i = 0;
	while((*envp)[i] != NULL)
	{
		if (ft_strncmp((*envp)[i], key, ft_strlen((*envp)[i]) == 0))
		{
			free((*envp)[i]);
			(*envp)[i] = entry;
			return ;
		}
		i++;
	}
}

void	add_env_var(char ***envp, char *key, char *value)
{
	char	*entry;
	char	*temp;
	char	**new_envp;
	int		i;

	temp = ft_strjoin(key, "=");
	entry = ft_strjoin(temp, value);
	free(temp);
	if (getenv(key) != NULL) //getenv geht nicht weil env von uns geaendert wird
	{
		replace_env_entry(envp, key, entry);
		return ;
	}
	i = 0;
	while ((*envp)[i] != NULL)
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while ((*envp)[i] != NULL)
	{
		new_envp[i] = (*envp)[i];
		i++;
	}
	new_envp[i] = entry;
	new_envp[i + 1] = NULL;
	free(*envp);
	*envp = new_envp;
}
