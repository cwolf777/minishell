/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:10:07 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/24 16:15:15 by phhofman         ###   ########.fr       */
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

static t_list *parse_text(char **prompt)
{
	int		token_len;
	char	quote_type;
	char	*cmd;

	token_len = 0;
	quote_type = 0;
	while (**prompt != '\0')
	{
		if (**prompt == '"' || **prompt == '\'')
		{
			if (quote_type == 0)
				quote_type = **prompt;
			else if(quote_type == **prompt)
				quote_type = 0;
		}
		else if (quote_type == 0 && (ft_strchr("\t\n\v\f\r ", **prompt) || is_symbol(*prompt, 0) != 'a'))
			break;
		(*prompt)++;
		token_len++;
	}
	cmd = ft_substr(*prompt - token_len, 0, token_len);
	if (quote_type != 0)
		cmd = 	open_quote_prompt(cmd, quote_type);
	return (ft_lstnew(token_init(TEXT, cmd)));
}

static t_list *parse_operator(char **prompt)
{
	char	symbol;
	char	*op;
	char	token_type;

	symbol = is_symbol(*prompt, 0);
	op = ft_char_to_str(symbol);
	if (!op)
		panic(NULL);
	if (ft_strchr("+#", symbol) != NULL)
		(*prompt) ++;
	(*prompt) ++;
	token_type = get_token_type(symbol);
	return (ft_lstnew(token_init(token_type, op)));
}

t_list	*tokenizer(char *prompt)
{
	t_list	*tokens;
	t_list	*expanded_tokens;
	t_list	*node;

	if (!prompt)
		return (NULL);
	tokens = NULL;
	while (*prompt != '\0')
	{
		skip_whitespace (&prompt);
		if (*prompt == '\0')
			break;
		if (is_symbol(prompt, 0) == 'a')
			node = parse_text(&prompt);
		else
			node = parse_operator(&prompt);
		ft_lstadd_back(&tokens, node);
	}
	expanded_tokens = ft_lstmap(tokens, expand_token, free_token);
	ft_lstclear(&tokens, free_token);
	return (expanded_tokens);
}

int	get_token_type(char	c)
{
	if (c == '#')
		return (HERE_DOC);
	if (c == '<' || c == '>' || c == '+')
		return (REDIR);
	if (c == '|')
		return (PIPE);
	if (c == ';')
		return (SEQ);
	if (c == '&')
		return (BACK);
	if (c == '(' || c == ')')
		return (PARENS);
	return (TEXT);
}