/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:42:30 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/10 10:40:04 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((unsigned char) *s1 == (unsigned char) *s2 && n > 1 && *s1)
	{
		s1 ++;
		s2 ++;
		n --;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
