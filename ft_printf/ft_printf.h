/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:35:13 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/10 15:59:18 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_str_len(char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putptr(uintptr_t ptr, char *base);
int	ft_put_unsigned(unsigned int n);
int	ft_count_digits(int n);

#endif