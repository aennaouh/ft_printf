/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:49:57 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/19 21:16:58 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char s, va_list countstr)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(countstr, int));
	else if (s == 's')
		count += ft_putstr(va_arg(countstr, char *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(countstr, int));
	else if (s == 'x' || s == 'X')
		count += ft_puthex(va_arg(countstr, int), s);
	else if (s == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_pointer(va_arg(countstr, unsigned long long));
	}
	else if (s == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(s);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	countstr;

	i = 0;
	count = 0;
	va_start(countstr, str);
	while (str[i])
	{
		if (str[i] == '%' && !str[i + 1])
			break ;
		else if (str[i] == '%')
			count += ft_check(str[++i], countstr);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(countstr);
	return (count);
}
