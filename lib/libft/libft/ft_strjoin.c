/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:55:53 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/13 16:11:25 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	joinlen;
	char	*join;

	joinlen = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (joinlen + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, joinlen + 1);
	ft_strlcat(join, s2, joinlen + 1);
	return (join);
}
