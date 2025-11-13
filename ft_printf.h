/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:12:49 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/13 17:38:23 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putnbr_base(long n, char *base);
int	ft_format_check1(char character, va_list ap);
int	ft_format_check2(char character, va_list ap);
int	ft_format_check3(char character, va_list ap);
int	ft_format_check4(char character, va_list ap);
int	ft_putchar(char c);
int	ft_putnbr_base_uintptr(uintptr_t n, char *base);

#endif