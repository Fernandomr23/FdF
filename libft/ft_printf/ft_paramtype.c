/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:52 by fmorenil          #+#    #+#             */
/*   Updated: 2024/04/05 18:42:36 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_paramtype(va_list vargs, const char c)
{
	int	param;

	param = 0;
	if (c == 'c')
		param += ft_putchar(va_arg(vargs, int));
	else if (c == 's')
		param += ft_putstr(va_arg(vargs, char *));
	else if (c == 'p')
		param += ft_putptr(va_arg(vargs, unsigned long long));
	else if (c == 'd' || c == 'i')
		param += ft_putnbr(va_arg(vargs, int));
	else if (c == 'u')
		param += ft_putuint(va_arg(vargs, unsigned int));
	else if (c == 'x' || c == 'X')
		param += ft_puthex(va_arg(vargs, int), c);
	else if (c == '%')
		param += ft_putpercentage();
	return (param);
}
