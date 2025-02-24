/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:43:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/24 13:42:40 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_env_name(char *str, int *i)
{
	int		start;
	char	*env_name;

	start = (*i);
	while (str[*i] && !ft_strchr("\t\n\v\f\r $", str[*i]))
		(*i)++;
	env_name = ft_substr(str, start, *i - start);
	if (!env_name)
		panic("malloc fail");
	return (env_name);
}
static char	*replace_env_variable(char *str, int *i, char *result)
{
	char	*temp;
	char	*env_name;
	char	*env_value;

	if (str[*i + 1] == ' ' || str[*i + 1] == '\0')
	{
		temp = result;
		result = ft_strjoin(temp, "$");
		free(temp);
		(*i)++;
		return (result);
	}
	(*i)++;
	env_name = extract_env_name(str, i);
	env_value = get_env_var(env_name);
	free(env_name);
	temp = result;
	result = ft_strjoin(temp, env_value);
	free(env_value);
	free(temp);
	if (!result)
		panic("malloc fail");
	return (result);
}

static char	*append_normal_text(char *str, int *i, char *result)
{
	int		start;
	char	*temp;
	char	*text_part;

	start = *i;
	while (str[*i] && str[*i] != '$')
		(*i)++;
	text_part = ft_substr(str, start, *i - start);
	if (!text_part)
		panic ("malloc fail");
	temp = result;
	result = ft_strjoin(temp, text_part);
	free(temp);
	free(text_part);
	if (!result)
		panic("malloc fail");
	return (result);
}
static char	*remove_quotes(char *str)
{
	char	*trimmed;

	if (*str == '"')
		trimmed = ft_strtrim(str, "\"");
	else
		trimmed = ft_strtrim(str, "\'");
	return (trimmed);
}

static char	*expand_variables_in_string(char *str)
{
	char	*result;
	int		i;

	result = ft_strdup("");
	if (!result)
		panic("malloc fail");

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			result = replace_env_variable(str, &i, result);
		else
			result = append_normal_text(str, &i, result);
	}
	return (result);
}

void	*expand_token(void	*content)
{
	t_token	*token;
	char	*str;
	char	*result;

	str = NULL;
	token = (t_token *)content;
	if (token->type != TEXT)
		return (token_init(token->type, ft_strdup(token->value)));
	if (*token->value == '$')
		return (token_init(token->type, get_env_var(token->value + 1)));
	str = remove_quotes(token->value);
	if (*token->value != '\"')
		return (token_init(token->type, str));
	
	result = expand_variables_in_string(str);	
	return (token_init(token->type, result));
}
