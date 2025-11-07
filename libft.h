/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshuhei <hshuhei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:12:49 by hshuhei           #+#    #+#             */
/*   Updated: 2025/11/07 16:20:27 by hshuhei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTT_H
# define LIBFTT_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
char	ft_printf_c(char c);

#endif