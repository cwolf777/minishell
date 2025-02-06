/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:35:34 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/06 10:37:44 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void free_memory(char **tokens, int i)
{
while (i >= 0)
{
	free(tokens[i]);
	i --;
}
free(tokens);
}

static size_t	count_tokens(char const *s, char *c)
{
size_t	token_count;
int		i;
int		inside_token;
token_count = 0;
i = 0;
while (s[i])
{
	inside_token = 0;
	while (s[i] != '\0' && ft_strchr(c, s[i]) == NULL)
	{
		inside_token = 1;
		i++;
	}
	if (inside_token)
		token_count++;
	if (s[i] != '\0')
		i++;
}
return (token_count);
}

static int	fill_tokens(char **tokens, char const *s, char *c)
{
int		token_len;
int		token_index;
char	*token;
token_index = 0;
while (*s)
{
	while (ft_strchr(c, *s) != NULL && *s)
		s ++;
	token_len = 0;
	while (ft_strchr(c, s[token_len]) == NULL && s[token_len] != '\0')
		token_len ++;
	if (token_len > 0)
	{
		token = ft_substr(s, 0, token_len);
		if (!token)
		{
			free_memory(tokens, token_index - 1);
			return (0);
		}
		tokens[token_index ++] = token;
		s += token_len;
	}
}
return (1);
}

char	**ft_split_2(char const *s, char *delimiters)
{
size_t	token_count;
char	**tokens;
if (!s)
	return (NULL);
token_count = count_tokens(s, delimiters);
tokens = (char **)malloc(sizeof(char *) * (token_count + 1));
if (!tokens)
	return (NULL);
tokens[token_count] = NULL;
if (!fill_tokens(tokens, s, delimiters))
	return (NULL);
return (tokens);
}
