/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:37:04 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/15 15:46:20 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_check1(char character, va_list ap)
{
	char	c;
	char	*s;
	int		total_len;

	total_len = 0;
	if (character == 'c')
	{
		c = (char)va_arg(ap, int);
		total_len += ft_putchar(c);
	}
	else if (character == 's')
	{
		s = va_arg(ap, char *);
		total_len += ft_putstr(s);
	}
	return (total_len);
}

int	ft_format_check2(char character, va_list ap)
{
	long long			di;
	unsigned long long	u;
	int					total_len;

	total_len = 0;
	if (character == 'd' || character == 'i')
	{
		di = va_arg(ap, int);
		if (di < 0)
		{
			total_len += write (1, "-", 1);
			di *= -1;
		}
		total_len += ft_putnbr_base(di, "0123456789");
	}
	else if (character == 'u')
	{
		u = va_arg(ap, unsigned int);
		total_len += ft_putnbr_base(u, "0123456789");
	}
	return (total_len);
}

int	ft_format_check3(char character, va_list ap)
{
	unsigned long long	x;
	unsigned long long	upper_x;
	int					total_len;

	total_len = 0;
	if (character == 'x')
	{
		x = va_arg(ap, unsigned int);
		total_len += ft_putnbr_base_hex(x, "0123456789abcdef");
	}
	else if (character == 'X')
	{
		upper_x = va_arg(ap, unsigned int);
		total_len += ft_putnbr_base_hex(upper_x, "0123456789ABCDEF");
	}
	return (total_len);
}

int	ft_format_check4(char character, va_list ap)
{
	uintptr_t		p;
	int				total_len;

	total_len = 0;
	if (character == 'p')
	{
		p = (uintptr_t)va_arg(ap, void *);
		if (p == 0)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		total_len += write(1, "0x", 2);
		total_len += ft_putnbr_base_hex(p, "0123456789abcdef");
	}
	else if (character == '%')
	{
		total_len += write(1, "%%", 1);
	}
	return (total_len);
}
