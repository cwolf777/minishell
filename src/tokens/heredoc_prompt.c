/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:58:01 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/26 13:03:02 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	found_delimeter(char *str, char *delimeter)
{
	if (ft_strncmp(str, delimeter, ft_strlen(delimeter)) == 0)
		return (1);
	return (0);
}

char	*open_heredoc_prompt(char *delimeter)
{
	char	*result;
	char	*temp;
	char	*input;

	result = ft_strdup("");
	while(1)
	{
		input = readline("heredoc> ");
		if (found_delimeter(input, delimeter) == 1)
		{
			break;
		}
		temp = ft_strjoin(input, "\n");
		free(input);
		input = ft_strjoin(result, temp);
		free(temp);
		free(result);
		result = input;
	}
	return (result);
}