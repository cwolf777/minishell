/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:09 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/11 13:49:41 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_s;

	new_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == (unsigned char) c)
			return ((void *)s + i);
		i ++;
	}
	return (NULL);
}
