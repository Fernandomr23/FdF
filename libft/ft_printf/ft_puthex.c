/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:50:08 by fmorenil          #+#    #+#             */
/*   Updated: 2024/04/08 12:34:23 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_puthex_neg(int n)
{
	long int	limit;

	limit = 4294967295;
	limit = limit + n + 1;
	return (limit);
}

static int	ft_createhex_min(char hex[], int i)
{
	int	param;

	param = 0;
	while (i >= 0)
	{
		if (hex[i] == 10)
			param += ft_putchar('a');
		else if (hex[i] == 11)
			param += ft_putchar('b');
		else if (hex[i] == 12)
			param += ft_putchar('c');
		else if (hex[i] == 13)
			param += ft_putchar('d');
		else if (hex[i] == 14)
			param += ft_putchar('e');
		else if (hex[i] == 15)
			param += ft_putchar('f');
		else
			param += ft_putnbr(hex[i]);
		i--;
	}
	return (param);
}

static int	ft_createhex_may(char hex[], int i)
{
	int	param;

	param = 0;
	while (i >= 0)
	{
		if (hex[i] == 10)
			param += ft_putchar('A');
		else if (hex[i] == 11)
			param += ft_putchar('B');
		else if (hex[i] == 12)
			param += ft_putchar('C');
		else if (hex[i] == 13)
			param += ft_putchar('D');
		else if (hex[i] == 14)
			param += ft_putchar('E');
		else if (hex[i] == 15)
			param += ft_putchar('F');
		else
			param += ft_putnbr(hex[i]);
		i--;
	}
	return (param);
}

int	ft_puthex(long int n, const char c)
{
	char	hex[999];
	int		param;
	int		i;

	param = 0;
	i = 0;
	if (n == 0)
		return (param += ft_putchar('0'));
	if (n < 0)
		n = ft_puthex_neg(n);
	while (n != 0)
	{
		hex[i] = n % 16;
		n = n / 16;
		i++;
	}
	i--;
	if (c == 'x')
		param += ft_createhex_min(hex, i);
	else
		param += ft_createhex_may(hex, i);
	return (param);
}
