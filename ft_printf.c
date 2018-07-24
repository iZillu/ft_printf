/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:23:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/22 17:09:12 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		detect_sign(va_list arg, const char *format, t_sym *sym)
{
	t_type	type;

		 if (*format == 's')
		sym->bits += print_s(arg, type.s, sym);
	else if (*format == 'i' || *format == 'd')
		sym->bits += print_i_or_d(arg, sym, &type.d);
	else if (*format == '%')
		sym->bits += print_percent();
	else if (*format == 'p')
		sym->bits += print_p(arg, &type.p);
	else if (*format == 'C')
		sym->bits += print_C(arg, &type.C);
	else if (*format == 'c')
		sym->bits += print_c(arg, &type.c);
	else if (*format == 'S')
		sym->bits += print_S(arg, type.S);
	else if (*format == 'D')
		sym->bits += print_D(arg, &type.D);
	else if (*format == 'o')
		sym->bits += print_o(arg, &type.o, sym);
	else if (*format == 'O')
		sym->bits += print_O(arg, &type.O, sym);
	else if (*format == 'u')
		sym->bits += print_u(arg, &type.u);
	else if (*format == 'U')
		sym->bits += print_U(arg, &type.U);
	else if (*format == 'x')
		sym->bits += print_x(arg, &type.x, sym);
	else if (*format == 'X')
		sym->bits += print_X(arg, &type.X, sym);
}

int	missing_flags(const char *format, t_sym *sym)
{	
	while (format[sym->i] == '+' || format[sym->i] == ' ' || format[sym->i] == '-'
		|| format[sym->i] == '#')
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
		if (format[sym->i] == '0') // d, i, o, u, x, X
			sym->zero = 1;
		sym->i += 1;
	}
	if (sym->minus == 1)
		sym->zero = 0;
	// здесь должна быть ширина
	if (format[sym->i] == '.')
		sym->precision = atoi(precision(format, sym));
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
	sym.i = sym.bits + sym.len;
	return (sym.i);
}
