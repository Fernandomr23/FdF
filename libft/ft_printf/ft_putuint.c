/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:05:57 by fmorenil          #+#    #+#             */
/*   Updated: 2024/03/28 14:10:21 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int n)
{
	int				param;

	param = 0;
	if (n > 9)
	{
		param += ft_putuint(n / 10);
		param += ft_putuint(n % 10);
	}
	else
		param += ft_putchar(n + '0');
	return (param);
}
