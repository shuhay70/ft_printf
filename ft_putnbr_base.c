/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:13:16 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/11 14:30:37 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(uintptr_t n, char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
	{
		count += write (1, "-", 1);
		n *= -1;
	}
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += write (1, &base[n % base_len], 1);
	return (count);
}
