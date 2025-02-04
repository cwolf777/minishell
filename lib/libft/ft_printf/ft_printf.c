/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:13:27 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/23 10:58:46 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format_specifier(char c, va_list ap)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'd' || c == 'i')
		printed_chars = ft_print_nbr(va_arg(ap, int));
	else if (c == 'u')
		printed_chars = ft_print_unsignednbr(va_arg(ap, unsigned int));
	else if (c == 's')
		printed_chars = ft_print_str(va_arg(ap, char *));
	else if (c == 'c')
		printed_chars = ft_print_char(va_arg(ap, int));
	else if (c == '%')
		printed_chars = ft_print_char('%');
	else if (c == 'x')
		printed_chars = \
		ft_print_hexnbr(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		printed_chars = \
		ft_print_hexnbr(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		printed_chars = ft_print_pointer(va_arg(ap, unsigned long));
	return (printed_chars);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	ap;
	int		i;
	int		printed_chars_count;
	int		format_output_count;

	i = 0;
	printed_chars_count = 0;
	va_start(ap, format_str);
	while (format_str[i])
	{
		if (format_str[i] == '%' && format_str[i + 1] != '\0')
			format_output_count = print_format_specifier(format_str[++i], ap);
		else if (format_str[i] != '%')
			format_output_count = ft_print_char(format_str[i]);
		if (format_output_count == -1)
			return (-1);
		printed_chars_count += format_output_count;
		i ++;
	}
	va_end(ap);
	return (printed_chars_count);
}
