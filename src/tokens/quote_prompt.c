/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:35:24 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/24 16:15:39 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	found_closing_quote(char *str, char qoute_type)
{
	int	i;
	int	qoute_count;
	
	i = 0;
	qoute_count = 0;
	while (str[i])
	{
		if (str[i] == qoute_type)
			qoute_count ++;
		i++;
	}
	if (qoute_count % 2 == 0)
		return (1);
	return (0);
}

char	*open_quote_prompt(char *prompt, char qoute_type)
{
	char	*result;
	char	*temp;
	char	*input;
	
	result = ft_strdup(prompt);
	while (1)
	{
		if (qoute_type == '"')
			input = readline("quote> ");
		else
			input = readline("qoute> ");
		temp = ft_strjoin("\n", input);
		free(input);
		input = ft_strjoin(result, temp);
		free(temp);
		free(result);
		result = input;
		if (found_closing_quote(result, qoute_type) == 1)
			break;
	}
	return (result);
}