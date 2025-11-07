/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:24:50 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/07 16:59:15 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_format_check(char character, va_list ap)
{
	char	c;
	//char	s;

	if (character == 'c')
		c = (char)va_arg(ap, int);
	//else if (character == 's')
	//{
	//	s = (char)va_arg(ap, char *);
	//	ft_printf_c(character);
	//}
	return (0);
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
			ft_format_check(format[i], ap);
		}
		else
			total_len += ft_putchar_len(format[i]);
	}
	va_end(ap);
	return (total_len);
}

int	main(void)
{
	printf("printf : %c\n", 'a');
	printf("printf : %c\n", ft_printf("%c", 'a'));
}
