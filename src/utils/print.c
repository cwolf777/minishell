/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:55:46 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/19 14:56:20 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_tokens(t_list *tokens)
{
	t_token	*token;

	token = (t_token *)tokens->content;
	printf("TOKEN: Type=%d, Value='%s'\n", token->type, token->value);
}

void	print_list(t_list *list)
{
	ft_printf("%s\n", list->content);
}

void	print_string_array(char **arr)
{
	int i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("%s ", arr[i]);
		i++;
	}
}
