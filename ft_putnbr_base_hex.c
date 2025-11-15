/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:13:16 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/13 18:47:55 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_hex(unsigned long long	n, char *base)
{
	int			count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_base_hex(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}
