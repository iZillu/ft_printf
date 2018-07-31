/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:23:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/27 00:19:20 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		detect_sign(va_list arg, const char *format, t_sym *sym)
{
	t_type	type;

	if (*format == 's')
		sym->bits += print_s(arg, sym, type.s);
	if (*format == 'i' || *format == 'd')
		sym->bits += print_i_or_d(arg, sym, &type.d);
	if (*format == '%')
		sym->bits += print_percent(sym);
	if (*format == 'p')
		sym->bits += print_p(arg, &type.p);
	if (*format == 'C')
		sym->bits += print_C(arg, &type.C);
	if (*format == 'c')
		sym->bits += print_c(arg, &type.c);
	if (*format == 'S')
		sym->bits += print_S(arg, type.S);
	if (*format == 'D')
		sym->bits += print_D(arg, &type.D);
	if (*format == 'o')
		sym->bits += print_o(arg, &type.o, sym);
	if (*format == 'O')
		sym->bits += print_O(arg, &type.O, sym);
	if (*format == 'u')
		sym->bits += print_u(arg, &type.u, sym);
	if (*format == 'U')
		sym->bits += print_U(arg, &type.U, sym);
	if (*format == 'x')
		sym->bits += print_x(arg, &type.x, sym);
	if (*format == 'X')
		sym->bits += print_X(arg, &type.X, sym);
}

int	missing_flags(const char *format, t_sym *sym)
{	
	while (format[sym->i] == '+' || format[sym->i] == ' ' || format[sym->i] == '-'
		|| format[sym->i] == '#' || format[sym->i] == '0')
	{
		if (format[sym->i] == '+')
			sym->sign = 1;
		if (format[sym->i] == ' ')
			if (sym->sign != 1)
				sym->sign = 2;
		if (format[sym->i] == '#')
			sym->sharp = 1;
		if (format[sym->i] == '-')
			sym->minus = 1;
		if (format[sym->i] == '0')
			sym->zero = 1;
		sym->i += 1;
	}
	if (sym->minus == 1)
		sym->zero = 0;
	if (format[sym->i] >= '0' && format[sym->i] <= '9')
	{
		sym->i--;
		sym->width = ft_atoi(ft_precision(format, sym));
	}
	if (format[sym->i] == '.')
	{
		sym->precision = ft_atoi(ft_precision(format, sym));
		sym->dot++;
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_sym 	sym;

	sym.sign = 0;
	sym.i = -1;
	sym.bits = 0;
	sym.len = 0;
	sym.sharp = 0;
	sym.precision = 0;
	sym.width = 0;
	sym.zero = 0;
	sym.minus = 0;
	sym.dot = 0;
	va_start(arg, format);
	while (format[++sym.i] != '\0')
	{
		while(format[sym.i] == '%')
		{
			sym.i++;
			missing_flags(format, &sym);
            detect_sign(arg, &format[sym.i++], &sym);
			va_end (arg);
		}
		if (format[sym.i] == '\0')
			break ;
		sym.bits++;
		write(1, &format[sym.i], 1);
	}
	sym.i = sym.bits;
	return (sym.i);
}
