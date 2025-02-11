/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:00:37 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/11 09:08:10 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	panic(char *error_msg)
{
	if (error_msg)
		ft_printf("%s",error_msg);
	exit(EXIT_FAILURE);
}

void	print_string_array(char **arr)
{
	int i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}

// char	**get_cmd_args(char **prompt)
// {
// 	int		i;
// 	char	**cmd_args;
// 	int		len;

// 	i = 0;
// 	len = i;
// 	while (prompt[i] != NULL)
// 	{
// 		if (ft_strncmp(";", prompt[i], 1) == 0)
// 		{
// 			cmd_args = copy_split(prompt, i);
// 			return (cmd_args);
// 		}
// 		i++;
// 	}
// 	cmd_args = copy_split(prompt, i);
// 	return (prompt);
// }

// char	**copy_split(char **split, int len)
// {
// 	char	**copy;
// 	int		i;

// 	copy = malloc(sizeof(char *) * len + 1);
// 	copy[len] = NULL;
// 	i = 0;
// 	while (i < len)
// 	{
// 		copy[i] = split[i];
// 		i++;
// 	}
// 	return (copy);
// }

// void	search_cmd(char **prompt)
// {
// 	int		i;
// 	char	**cmd_args;

// 	i = 0;
// 	while (prompt[i] != NULL)
// 	{
// 		cmd_args = get_cmd_args(prompt);
// 		i++;
// 	}
// }