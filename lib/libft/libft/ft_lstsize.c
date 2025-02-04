/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:06:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/16 14:38:34 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*curr;

	curr = lst;
	size = 0;
	while (curr)
	{
		curr = curr->next;
		size ++;
	}
	return (size);
}
