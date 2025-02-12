/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:10:07 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/12 15:45:11 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// t_list	*tokinizer(t_list	*list)
// {
// 	t_list	*curr;
// 	char	**cmd_args;
// 	t_cmd	*cmd;

// 	curr = list;
// 	while (curr != NULL)
// 	{
// 		if (ft_strlen(curr->content) > 1)
// 		{
// 			if (ft_strncmp("<", curr->content, 2) == 0)
// 			{
// 				cmd = redir_cmd_init()
// 			}
// 		}
// 		else
// 		{
// 			cmd_args = ft_split2(curr->content, " \t\n\v\f\r");
// 			 exec_cmd_init(cmd_args);
// 		}
// 	}
// }