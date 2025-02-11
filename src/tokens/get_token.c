/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:10:07 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/11 15:31:52 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void	print(t_list * list);
char	is_symbol(char *str);

char	**find_cmd_args(char **prompt, int start, int len)
{
	char **cmd_args = malloc (sizeof(char *) * len);

	while (start < len)
	{
		cmd_args[start] = prompt[start];
		start ++;
	}
	cmd_args[len] = NULL;
	return (cmd_args);
}

void	get_token(char *prompt)
{
	int	token_len;
	t_list	*tokens;
	t_list	*node;
	char	c;

	tokens = NULL;
	while (*prompt != '\0')
	{
		while (ft_strchr("\t\n\v\f\r ", *prompt) != NULL && *prompt != '\0')
			prompt ++;
		
		token_len = 0;
		if (is_symbol(prompt) == 'a')
		{
			while (is_symbol(prompt) == 'a')
			{
				prompt ++;
				token_len ++;
			}
			char *cmd = ft_substr(prompt - token_len, 0, token_len);
			node = ft_lstnew(cmd);
		}
		else if (is_symbol(prompt) != '\0')
		{
			c = is_symbol(prompt);
			char *p = &c;
			node = ft_lstnew(p);
			if (is_symbol(prompt) == '+')
				prompt ++;
			prompt ++;
		}
		ft_lstadd_back(&tokens, node);
	}
	ft_lstiter(tokens, print);
	return ;
}

char	is_symbol(char *str)
{
	if (str[0] == '\0')
		return ('\0');
	if (str[0] == '>' && str[1] == '>')
		return ('+');
	if (ft_strchr("();|&<>", str[0]) == NULL)
		return ('a');
	return (str[0]);
}

void	print(t_list *list)
{
	ft_printf("%s\n", list->content);
}