/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:27:42 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/15 13:02:14 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	unsigned int	i;
	char			*new_s;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	new_s = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i ++;
	}
	new_s[i] = '\0';
	return (new_s);
}
