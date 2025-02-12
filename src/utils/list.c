/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:19:37 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/12 15:06:32 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	is_symbol(char *str, int in_quotes)
{
	if (in_quotes != 0)
		return ('a');
	if (str[0] == '\0')
		return ('\0');
	if (str[0] == '>' && str[1] == '>')
		return ('+');
	if (str[0] == '<' && str[1] == '<')
		return ('#');
	if (ft_strchr("();|&<>", str[0]) == NULL)
		return ('a');
	return (str[0]);
}

static void	skip_whitespace(char **prompt)
{
	while (ft_strchr("\t\n\v\f\r ", **prompt) != NULL && **prompt != '\0')
			(*prompt) ++;
}

static t_list *parse_cmd(char **prompt)
{
	int		token_len;
	char	quote_type;
	char	*cmd;

	token_len = 0;
	quote_type = 0;
	while (**prompt != '\0' && (is_symbol(*prompt, quote_type) == 'a'))
	{
		if (**prompt == '"' || **prompt == '\'')
		{
			if (quote_type == 0)
				quote_type = **prompt;
			else if(quote_type == **prompt)
				quote_type = 0;
		}
		(*prompt)++;
		token_len++;
	}
	cmd = ft_substr(*prompt - token_len, 0, token_len);
	if (quote_type != 0)
		panic("quote fail");
	return ft_lstnew(cmd);
}

static t_list *parse_operator(char **prompt)
{
	char symbol;
	char *op;

	symbol = is_symbol(*prompt, 0);
	op = ft_char_to_str(symbol);
	if (!op)
		panic(NULL);
	if (ft_strchr("+#", symbol) != NULL)
		(*prompt) ++;
	(*prompt) ++;
	return ft_lstnew(op);
}

t_list	*convert_prompt_to_list(char *prompt)
{
	t_list	*tokens;
	t_list	*node;

	tokens = NULL;
	while (*prompt != '\0')
	{
		skip_whitespace (&prompt);
		if (*prompt == '\0')
			break;
		if (is_symbol(prompt, 0) == 'a')
			node = parse_cmd(&prompt);
		else
			node = parse_operator(&prompt);
		ft_lstadd_back(&tokens, node);
	}
	return (tokens);
}


