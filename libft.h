/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:12:49 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/10 16:11:41 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTT_H
# define LIBFTT_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr(char *str);
int		ft_putnbr_base(long n, char *base);
int		ft_format_check1(char character, va_list ap);
int		ft_format_check2(char character, va_list ap);
int		ft_format_check3(char character, va_list ap);

#endif