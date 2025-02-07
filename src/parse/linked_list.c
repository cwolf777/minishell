/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:58:36 by cwolf             #+#    #+#             */
/*   Updated: 2025/02/07 14:34:32 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_node(t_list **head, void *data)
{
	t_list	*new;
	t_list	*temp;

	new = ft_lstnew(data);
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

