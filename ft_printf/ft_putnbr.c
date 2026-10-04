/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:19:50 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/10 16:00:02 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		i;
	char	c;

	i = n;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		if (n < 10)
		{
			c = (n % 10) + '0';
			write(1, &c, 1);
			return (ft_count_digits(i));
		}
		ft_putnbr(n / 10);
	}
	else if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (ft_count_digits(i));
}
