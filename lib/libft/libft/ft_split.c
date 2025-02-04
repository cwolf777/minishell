/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:08:17 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/15 10:11:55 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	free_memory(char **tokens, int i)
{
	while (i >= 0)
	{
		free(tokens[i]);
		i --;
	}
	free(tokens);
}

static size_t	count_tokens(char const *s, char c)
{
	size_t	token_count;
	int		i;
	int		inside_token;

	token_count = 0;
	i = 0;
	while (s[i])
	{
		inside_token = 0;
		while (s[i] != c && s[i] != '\0')
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

static int	fill_tokens(char **tokens, char const *s, char c)
{
	int		token_len;
	int		token_index;
	char	*token;

	token_index = 0;
	while (*s)
	{
		while (*s == c && *s)
			s ++;
		token_len = 0;
		while (s[token_len] != c && s[token_len] != '\0')
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

char	**ft_split(char const *s, char c)
{
	size_t	token_count;
	char	**tokens;

	if (!s)
		return (NULL);
	token_count = count_tokens(s, c);
	tokens = (char **)malloc(sizeof(char *) * (token_count + 1));
	if (!tokens)
		return (NULL);
	tokens[token_count] = NULL;
	if (!fill_tokens(tokens, s, c))
		return (NULL);
	return (tokens);
}
