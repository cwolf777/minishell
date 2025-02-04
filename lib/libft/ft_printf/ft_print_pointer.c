/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:06 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/23 11:00:30 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long ptr)
{
	int	printed_chars_count;
	int	temp;

	printed_chars_count = 0;
	temp = ft_print_str("0x");
	if (temp == -1)
		return (-1);
	printed_chars_count += temp;
	temp = ft_print_hexnbr(ptr, "0123456789abcdef");
	if (temp == -1)
		return (-1);
	printed_chars_count += temp;
	return (printed_chars_count);
}
