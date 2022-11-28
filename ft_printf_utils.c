/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:23:53 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/19 22:20:27 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		count += write(1, "(null)", 6);
	else
	{
		while (str[i] != '\0')
		{
			count += write(1, &str[i], 1);
			i++;
		}
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int		count;

	count = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		count += ft_putchar(nb + 48);
	}
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}
