/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:24:50 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/11 12:48:28 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total_len;
	int		i;

	i = 0;
	total_len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c' || format[i] == 's')
			{
				total_len += ft_format_check1(format[i], ap);
				i++;
			}
			if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u' )
			{
				total_len += ft_format_check2(format[i], ap);
				i++;
			}
			if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
			{
				total_len += ft_format_check3(format[i], ap);
				i++;
			}
		}
		else
			total_len += ft_putchar_len(format[i]);
	}
	va_end(ap);
	return (total_len);
}

int	main(void)
{
	ft_printf("%X", 555);
}
