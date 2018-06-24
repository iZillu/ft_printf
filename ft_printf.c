/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:23:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/24 05:23:02 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	detect_sign(va_list arg, const char *format)
{
	t_type	type;

	if (*format == 's')
	{
		type.str = va_arg(arg, char *);
		ft_putstr(type.str);
	}
	if (*format == 'i' || *format == 'd')
		ft_putnbr(type.x = va_arg(arg, int));
	if (*format == '%')
		write(1, "%", 1);

		
}

int	ft_printf(const char * restrict format, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, format);
	i = -1;
	while (format[++i])
	{
		while(format[i] == '%')
		{
			i++;
			detect_sign(arg, &format[i++]);
			va_end (arg);
		}
		write(1, &format[i], 1);
	}
	return (1);
}