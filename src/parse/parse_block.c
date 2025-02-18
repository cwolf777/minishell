/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:50:17 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/18 09:50:25 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_block(t_list **list)
{
	t_cmd	*cmd;
	t_token	*token;

	token = (t_token *)(*list)->content;
	if (ft_strncmp("(", token->value, 2) != 0)
		panic("parse_block error");
	*list = (*list)->next;
	cmd = parse_line(list);
	token = (t_token *)(*list)->content;
	if (ft_strncmp(")", token->value, 2) != 0)
		panic("syntax error missing ')'");
	*list = (*list)->next;
	cmd = parse_redir(list, cmd);
	return (cmd);
}
