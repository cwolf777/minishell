/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:20:09 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/11 13:50:15 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	if (n == 0)
		return (0);
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while ((unsigned char) *new_s1 == (unsigned char) *new_s2 && n > 1)
	{
		new_s1 ++;
		new_s2 ++;
		n --;
	}
	return ((unsigned char) *new_s1 - (unsigned char) *new_s2);
}
