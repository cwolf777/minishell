/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:10 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/23 11:08:52 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digit_count(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static void	convert_number_to_string(char *str, int n, size_t i)
{
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i --;
	}
}

int	ft_print_nbr(int n)
{
	char	*result_str;
	int		len;
	int		is_negative;

	is_negative = 0;
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n == 0)
		return (ft_print_str("0"));
	if (n < 0)
	{
		n = -n;
		is_negative = 1;
	}
	len = get_digit_count(n) + is_negative;
	result_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!result_str)
		return (-1);
	result_str[len] = '\0';
	convert_number_to_string(result_str, n, len - 1);
	if (is_negative)
		result_str[0] = '-';
	len = ft_print_str(result_str);
	free(result_str);
	return (len);
}
