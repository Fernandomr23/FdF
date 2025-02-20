/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:49:41 by fmorenil          #+#    #+#             */
/*   Updated: 2024/04/04 14:28:37 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		param;
	int		i;

	va_start(vargs, str);
	param = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			param += ft_paramtype(vargs, str[i + 1]);
			i++;
		}
		else
			param += ft_putchar(str[i]);
		i++;
	}
	va_end(vargs);
	return (param);
}
