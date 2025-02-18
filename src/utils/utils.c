/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:00:37 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:44 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	panic(char *error_msg)
{
	if (error_msg)
		ft_printf("%s",error_msg);
	exit(EXIT_FAILURE);
}

int	fork_plus()
{
	int	pid;

	pid = fork();
	if (pid < 0)
		panic("fork fail");
	return (pid);
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
void	print_list(t_list *list)
{
	ft_printf("%s\n", list->content);
}

char	*ft_char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void print_tokens(t_list *tokens)
{
	t_token	*token;

	token = (t_token *)tokens->content;
	printf("TOKEN: Type=%d, Value='%s'\n", token->type, token->value);
}