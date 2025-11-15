/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:13:16 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/15 14:57:03 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long n, char *base)
{
	int		total_len;

	total_len = 0;
	if (n >= 10)
		total_len += ft_putnbr_base(n / 10, base);
	total_len += write (1, &base[n % 10], 1);
	return (total_len);
}
