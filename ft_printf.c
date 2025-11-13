/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:24:50 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/13 17:06:21 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conditional_statement(char c, int total_len, va_list *ap)
{
	if (c == 'c' || c == 's')
		total_len += ft_format_check1(c, ap);
	else if (c == 'd' || c == 'i' || c == 'u')
		total_len += ft_format_check2(c, ap);
	else if (c == 'x' || c == 'X')
		total_len += ft_format_check3(c, ap);
	else if (c == 'p' || c == '%')
		total_len += ft_format_check4(c, ap);
	return (total_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total_len;
	int		i;

	i = 0;
	total_len = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total_len = conditional_statement(format[i], total_len, ap);
		}
		else
			total_len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (total_len);
}

//int	main(void)
//{
//	int	i;

//	// ft_printf("ft_printf ; %p\n", 0);
//	// printf("printf ; %p\n", 0);
//	// ft_printf("ft_printf ; %%%%%\n", NULL);
//	// printf("printf ; %%%%%\n", NULL);
//	//i = ft_printf(NULL);
//	//printf("%d\n", i);
//	//i = printf(NULL);
//	//printf("%d\n", i);
//	//return (0);
//	ft_printf("ft_printf ; %s\n", "asdf");
//	printf("printf ; %s\n", "asdf");
//}
