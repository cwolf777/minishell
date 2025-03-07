/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:44:44 by phhofman          #+#    #+#             */
/*   Updated: 2025/03/07 14:07:23 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_cmd(t_list **list) //done
{
	t_cmd	*cmd;

	cmd = parse_line(list);
	if (*list != NULL)
		panic("syntax error, leftovers in prompt");
	return (cmd);
}


