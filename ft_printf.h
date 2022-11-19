/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:25:21 by aennaouh          #+#    #+#             */
/*   Updated: 2022/11/19 22:22:38 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_pointer(unsigned long long n);
int	ft_putunsigned(unsigned int nb);
int	ft_puthex(unsigned int n, char str);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_printf(const char *str, ...);

#endif