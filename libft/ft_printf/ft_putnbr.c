/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:27:29 by fmorenil          #+#    #+#             */
/*   Updated: 2024/03/28 15:41:05 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	param;

	param = 0;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		param += 2;
		param += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		n *= -1;
		param += ft_putchar('-');
		param += ft_putnbr(n);
	}
	else if (n > 9)
	{
		param += ft_putnbr(n / 10);
		param += ft_putnbr(n % 10);
	}
	else
		param += ft_putchar(n + '0');
	return (param);
}
