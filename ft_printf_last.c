/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:36:56 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/19 21:39:17 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char str)
{
	unsigned int	i;
	int				count;
	char			*base;

	count = 0;
	if (str == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	if (n < 16)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_puthex(n / 16, str);
		count += ft_puthex(n % 16, str);
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	else
	{
		c = n + 48;
		count += write(1, &c, 1);
	}
}

int	ft_pointer(unsigned long long n)
{
	int				count;

	count = 0;
	if (n < 16)
		count += ft_puthex(n, 'x');
	else
	{
		count += ft_pointer(n / 16);
		count += ft_pointer(n % 16);
	}
	return (count);
}