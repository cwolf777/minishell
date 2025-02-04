/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:22:20 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/14 11:04:17 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	start = 0;
	while (s1[start] && is_in_set(set, s1[start]))
		start ++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && is_in_set(set, s1[end]))
		end --;
	if (start > end)
		return (ft_strdup(""));
	trim = ft_substr(s1, start, (end - start + 1));
	return (trim);
}
