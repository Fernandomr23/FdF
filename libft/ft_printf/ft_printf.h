/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:33:24 by fmorenil          #+#    #+#             */
/*   Updated: 2024/04/05 18:37:42 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_paramtype(va_list vargs, const char c);
int	ft_putpercentage(void);
int	ft_putnbr(int n);
int	ft_putuint(unsigned int n);
int	ft_puthex(long int n, const char c);
int	ft_putptr(unsigned long long ptr);

#endif
