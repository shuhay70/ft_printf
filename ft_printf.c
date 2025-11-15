/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:24:50 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/15 16:11:21 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conditional_statement(char c, int total_len, va_list ap)
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

//#include <stdio.h>
//#include <limits.h>

//int	main(void)
//{
//	printf(" %u ", 9);
//}

//#include <stdio.h>
//#include <limits.h>
//int	main(void)
//{
//	int ret1, ret2;
//	int x = 42;
//	void *p = &x;

//	printf("===== CHARACTER =====\n");
//	ret1 = ft_printf("%c", 'A');
//	printf("\n");
//	ret2 = printf("%c", 'A');
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%c", '\0');
//	printf("\n");
//	ret2 = printf("%c", '\0');
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	printf("===== STRING =====\n");
//	ret1 = ft_printf("%s", "hello");
//	printf("\n");
//	ret2 = printf("%s", "hello");
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%s", "");
//	printf("\n");
//	ret2 = printf("%s", "");
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%s", (char *)NULL);
//	printf("\n");
//	ret2 = printf("%s", (char *)NULL);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	printf("===== POINTER =====\n");
//	ret1 = ft_printf("%p", (void *)0);
//	printf("\n");
//	ret2 = printf("%p", (void *)0);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%p", p);
//	printf("\n");
//	ret2 = printf("%p", p);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	printf("===== INTEGER =====\n");
//	ret1 = ft_printf("%d", 42);
//	printf("\n");
//	ret2 = printf("%d", 42);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%d", -42);
//	printf("\n");
//	ret2 = printf("%d", -42);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%d", INT_MIN);
//	printf("\n");
//	ret2 = printf("%d", INT_MIN);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%d", INT_MAX);
//	printf("\n");
//	ret2 = printf("%d", INT_MAX);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	printf("===== UNSIGNED =====\n");
//	ret1 = ft_printf("%u", 0u);
//	printf("\n");
//	ret2 = printf("%u", 0u);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%u", 4294967295u);
//	printf("\n");
//	ret2 = printf("%u", 4294967295u);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	printf("===== HEX =====\n");
//	ret1 = ft_printf("%x", 255);
//	printf("\n");
//	ret2 = printf("%x", 255);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%X", 255);
//	printf("\n");
//	ret2 = printf("%X", 255);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%x", -1);
//	printf("\n");
//	ret2 = printf("%x", -1);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	ret1 = ft_printf("%x", INT_MIN);
//	printf("\n");
//	ret2 = printf("%x", INT_MIN);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	printf("===== MIXED =====\n");
//	ret1 = ft_printf("%c%s%d%u%x%p%%", 'A', "abc", -42, 123u, 255, p);
//	printf("\n");
//	ret2 = printf("%c%s%d%u%x%p%%", 'A', "abc", -42, 123u, 255, p);
//	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

//	return (0);
//}
