/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:56:56 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/16 14:38:07 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr_node;
	t_list	*next_node;

	if (!lst && !*lst)
		return ;
	curr_node = *lst;
	while (curr_node)
	{
		next_node = curr_node->next;
		del(curr_node->content);
		free(curr_node);
		curr_node = next_node;
	}
	*lst = NULL;
}
