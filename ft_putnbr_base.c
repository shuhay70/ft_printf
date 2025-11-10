/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:13:16 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/10 15:40:30 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr_base(long n, char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
	{
		count += write (1, '-', 1);
		n *= -1;
	}
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += write (1, &base[n % base_len], 1);
	return (count);
}
