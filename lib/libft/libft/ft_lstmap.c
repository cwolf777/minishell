/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:40:20 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/17 13:16:12 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*head;
	void	*ptr;

	if (!lst)
		return (NULL);
	head = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		new_node = ft_lstnew(ptr);
		if (!new_node)
		{
			del(ptr);
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = new_node;
		else
			ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}
