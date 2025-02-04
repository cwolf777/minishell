/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:17:32 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/23 11:09:18 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexnbr(unsigned long n, char *hex_format)
{
	int	write_count;
	int	check_error;

	write_count = 0;
	check_error = 0;
	if (n < 16)
	{
		if (ft_print_char(hex_format[n]) == -1)
			return (-1);
		return (1);
	}
	check_error = ft_print_hexnbr(n / 16, hex_format);
	if (check_error == -1)
		return (-1);
	write_count += check_error;
	if (ft_print_char(hex_format[n % 16]) == -1)
		return (-1);
	write_count++;
	return (write_count);
}
