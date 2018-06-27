/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:23:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/27 01:57:18 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t		detect_sign(va_list arg, const char *format, int *sign)
{
	t_sym	sym;
	t_type	type;

	sym.bits = 0;
	if (*format == 's')
		sym.bits = print_s(arg, type.s);
	else if (*format == 'i' || *format == 'd')
		sym.bits = print_i_or_d(arg, sign, &type.d);
	else if (*format == '%')
	{
		sym.bits = 1;
		write(1, "%", 1);
	}
	else if (*format == 'p')
		sym.bits = print_p(arg, &type.p);
	else if (*format == 'C')
		sym.bits = print_C(arg, &type.C);
	else if (*format == 'c')
		sym.bits = print_c(arg, &type.c);
	else if (*format == 'S')
		sym.bits = print_S(arg, type.S);
	else if (*format == 'D')
		sym.bits = print_D(arg, &type.D);
	else if (*format == 'o')
		sym.bits = print_o(arg, &type.o);
	else if (*format == 'O')
		sym.bits = print_O(arg, &type.O);
	else if (*format == 'u')
		sym.bits = print_u(arg, &type.u);
	else if (*format == 'U')
		sym.bits = print_U(arg, &type.U);
	else if (*format == 'x')
		sym.bits = print_x(arg, &type.x);
	else if (*format == 'X')
		sym.bits = print_X(arg, &type.X);
	return (sym.bits);
}

int	missing_sign(const char *format, int *sign, int *i)
{
	int len;

	len = 0;
	while (format[*i] == '+' || format[*i] == ' ')
	{
		if (format[*i] == '+')
			*sign = 1;
		if (format[*i] == ' ')
			if (*sign != 1)
				*sign = 2;

		i++;
	}
	if (*sign == 2)
		len++;
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_sym 	sym;

	sym.sign = 0;
	sym.i = -1;
	sym.bits = 0;
	sym.len = 0;
	va_start(arg, format);
	while (format[++sym.i] != '\0')
	{
		while(format[sym.i] == '%')
		{
			sym.i++;
			sym.len++;
			if (missing_sign(format, &sym.sign, &sym.i))
				sym.len++;
			if (sym.bits += detect_sign(arg, &format[sym.i++], &sym.sign))
				sym.len++;
			va_end (arg);
		}
		if (format[sym.i] == '\0')
			break ;
		write(1, &format[sym.i], 1);
	}
	sym.i = sym.i + sym.bits - sym.len;
	return (sym.i);
}
