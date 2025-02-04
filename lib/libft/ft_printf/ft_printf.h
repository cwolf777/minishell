/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:31:17 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/24 14:00:32 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_print_unsignednbr(unsigned int n);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_char(char c);
int	ft_printf(const char *fromat_str, ...);
int	ft_print_hexnbr(unsigned long n, char *hex_format);
int	ft_print_pointer(unsigned long ptr);
int	ft_printf(const char *format_str, ...);

#endif