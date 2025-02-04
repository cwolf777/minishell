/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:41:50 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/16 09:38:32 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (*haystack && i < len)
	{
		j = 0;
		while (haystack[j] == needle[j] && haystack[j] != '\0' && i + j < len)
			j ++;
		if (needle[j] == '\0')
			return ((char *)haystack);
		haystack ++;
		i ++;
	}
	return (NULL);
}
