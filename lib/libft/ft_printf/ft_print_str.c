/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:59:21 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/22 10:04:43 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	write_length;

	write_length = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (-1);
		write_length++;
		s++;
	}
	return (write_length);
}
