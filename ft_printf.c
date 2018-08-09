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

size_t		detect_sign(va_list arg, const char *format, t_sym *sym)
{
	t_type	type;

	if (*format == 's')
		return (sym->bits += print_s(arg, sym, type.s));
	else if (*format == 'i' || *format == 'd')
		return (sym->bits += print_i_or_d(arg, sym, &type.d));
	else if (*format == '%')
		return (sym->bits += print_percent(sym));
	else if (*format == 'p')
		return (sym->bits += print_p(arg, &type.p, sym));
	else if (*format == 'C')
		return (sym->bits += print_C(arg, &type.C, sym));
	else if (*format == 'c')
		return (sym->bits += print_c(arg, &type.c, sym));
	else if (*format == 'S')
		return (sym->bits += print_S(arg, type.S, sym));
	else if (*format == 'D')
		return (sym->bits += print_D(arg, &type.D, sym));
	else if (*format == 'o')
		return (sym->bits += print_o(arg, &type.o, sym));
	else if (*format == 'O')
		return (sym->bits += print_O(arg, &type.O, sym));
	else if (*format == 'u')
		return (sym->bits += print_u(arg, &type.u, sym));
	else if (*format == 'U')
		return (sym->bits += print_U(arg, &type.U, sym));
	else if (*format == 'x')
		return (sym->bits += print_x(arg, &type.x, sym));
	else if (*format == 'X')
		return (sym->bits += print_X(arg, &type.X, sym));
	else
		return (0);
}

// придумать что-то с ретёрном в детект сайне, нужно не сдвигать итератор если никакого знака не было

void	checking_sizes(const char *format, t_sym *sym)
{
	while (format[sym->i] == 'h' || format[sym->i] == 'l' || format[sym->i] == 'j'
		|| format[sym->i] == 'z')
	{
		if (ft_strncmp("hh", &format[sym->i], 2) == 0 && sym->size < 1)
		{
			sym->size = 1;
			sym->i++;
		}
		else if (ft_strncmp("ll", &format[sym->i], 2) == 0 && sym->size < 4)
		{
			sym->size = 4;
			sym->i++;
		}
		else if (format[sym->i] == 'h' && sym->size < 2)
			sym->size = 2;
		else if (format[sym->i] == 'l' && sym->size < 3)
			sym->size = 3;
		else if (format[sym->i] == 'j' && sym->size < 5)
			sym->size = 5;
		else if (format[sym->i] == 'z' && sym->size < 6)
			sym->size = 6;
		sym->i++;
	}
	/* 1 = hh  ;   2 = h
	// 3 = l   ;   4 = ll
	// 5 = j   ;   6 = z
	*/
}

void	missing_flags(const char *format, t_sym *sym)
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
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_sym 	sym;

	sym.i = -1;
	sym.bits = 0;
	initializer(&sym);
	va_start(arg, format);
	while (format[++sym.i] != '\0')
	{
		while(format[sym.i] == '%')
		{
			sym.i++;
			if (format[sym.i] == '\0')
				break ;
			missing_flags(format, &sym);
			checking_sizes(format, &sym);
            if (detect_sign(arg, &format[sym.i], &sym))
            	sym.i++;
            initializer(&sym);
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
