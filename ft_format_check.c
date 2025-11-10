/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:37:04 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/08 19:00:34 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_format_check1(char character, va_list ap)
{
	char			c;
	char			*s;

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

static int	ft_format_check2(char character, va_list ap)
{
	int				di;
	unsigned int	u;

	else if (character == 'd' || character == 'i')
	{
		di = va_arg(ap, int);
		total_len += ft_putnbr_base(di, "0123456789");
	}
	else if (character == 'u')
	{
		u = va_arg(ap, unsigned int);
		total_len += ft_putnbr_base(u, "0123456789");
	}
	return (total_len);
}

static int	ft_format_check3(char character, va_list ap)
{
	unsigned int	x;
	unsigned int	upper_x;
	unsigned long	p;

	else if (character == 'x')
	{
		x = va_arg(ap, unsigned int);
		total_len += ft_putnbr_base(x, "0123456789abcdef");
	}
	else if (character == 'X')
	{
		upper_x = va_arg(ap, unsigned int);
		total_len += ft_putnbr_base(upper_x, "0123456789ABCDEF");
	}
	else if (format[i] == 'p')
	{
		p_ptr = va_arg(ap, void *);
        p = (unsigned long)p_ptr;
		total_len += write(1, "0x", 2);
		total_len += ft_putnbr_base(p, "0123456789abcdef");
	}
	return (total_len);
}
