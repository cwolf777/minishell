/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:15:05 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/10 16:16:18 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (new_src < new_dst)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			new_dst[i] = new_src[i];
			i --;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
