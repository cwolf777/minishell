/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:04:51 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/21 10:00:31 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		sum;

	sign = 1;
	while (ft_iswhitespace(*str) && *str)
		str ++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str ++;
	}
	sum = 0;
	while (ft_isdigit(*str))
	{
		sum = sum * 10 + (*str - '0');
		str ++;
	}
	return (sign * sum);
}
