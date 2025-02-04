/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:26:46 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/04 10:47:03 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buf( char **buffer)
{
	free(*buffer);
	*buffer = NULL;
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	joinlen;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	joinlen = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (joinlen + 1));
	if (!join)
	{
		free_buf(&s1);
		return (NULL);
	}
	ft_strlcpy(join, s1, joinlen + 1);
	ft_strlcat(join, s2, joinlen + 1);
	free_buf(&s1);
	return (join);
}
