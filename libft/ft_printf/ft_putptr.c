/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:55:28 by fmorenil          #+#    #+#             */
/*   Updated: 2024/04/08 12:20:38 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_createptr(unsigned long long ptr)
{
	int	param;

	param = 0;
	if (ptr >= 16)
	{
		param += ft_createptr(ptr / 16);
		param += ft_createptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			param += ft_putchar(ptr + '0');
		else
			param += ft_putchar(ptr - 10 + 'a');
	}
	return (param);
}

int	ft_putptr(unsigned long long ptr)
{
	int					param;

	param = 0;
	param += ft_putchar('0');
	param += ft_putchar('x');
	param += ft_createptr(ptr);
	return (param);
}
