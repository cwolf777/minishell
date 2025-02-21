/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:43:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/21 13:42:23 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_env_var(char *env_var)
{
	char	*value;

	value = getenv(env_var);
	if (!value)
		return ("");
	return (value);
}
static char	*replace_env_variable(char *str, int *i, char *result)
{
	char	*temp;
	char	*env_name;
	char	*env_value;

	int		start;

	start = ++(*i);
	while (str[*i] && !ft_strchr("\t\n\v\f\r $", str[*i]))
		(*i)++;
	env_name = ft_substr(str, start, *i - start);
	if (!env_name)
		panic("malloc fail");
	env_value = expand_env_var(env_name);
	free(env_name);
	temp = result;
	result = ft_strjoin(temp, env_value);
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

t_token	*expanse(void	*input)
{
	char	*str;
	char	*result;
	int		i;

	str = (char *)input;
	if (*str == '$')
		return (expand_env_var(str + 1));
	if (*str != '"' && ft_strchr(str, '$') == NULL)
		return (str);
	result = ft_strdup("");
	if (!result)
		panic("malloc fail");
	i = 0;
	while(str[i])
	{
		if (str[i] == '$')
			result = replace_env_variable(str, &i, result);
		else
			result = append_normal_text(str, &i , result);
	}
	return (token_init(TEXT, result));
}
