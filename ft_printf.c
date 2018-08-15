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
		sym->size == 3 ? (sym->bits += print_S(arg, type.S, sym)) : (sym->bits += print_s(arg, sym, type.s));
	else if (*format == 'c')
		sym->size == 3 ? (sym->bits += print_C(arg, &type.C, sym)) : (sym->bits += print_c(arg, &type.c, sym));
	else (*format == 'i' || *format == 'd') ? sym->bits += print_i_or_d(arg, sym, &type.d)
	: *format == 'p' ? sym->bits += print_p(arg, &type.p, sym)
	: *format == '%' ? sym->bits += print_percent(sym)
	: *format == 'C' ? sym->bits += print_C(arg, &type.C, sym)
	: *format == 'S' ? sym->bits += print_S(arg, type.S, sym)
	: *format == 'D' ? sym->bits += print_D(arg, &type.D, sym)
	: *format == 'o' ? sym->bits += print_o(arg, &type.o, sym)
	: *format == 'O' ? sym->bits += print_O(arg, &type.O, sym)
	: *format == 'u' ? sym->bits += print_u(arg, &type.u, sym)
	: *format == 'U' ? sym->bits += print_U(arg, &type.U, sym)
	: *format == 'x' ? sym->bits += print_x(arg, &type.x, sym)
	: *format == 'X' ? sym->bits += print_X(arg, &type.X, sym)
	: --sym->crutch;
}

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

char	*ft_precision(const char *format, t_sym *sym)
{
	char	*str;
	int		len;
	int		num;

	num = 0;
	len = 0;
	while (format[++sym->i] >= '0' && format[sym->i] <= '9')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	sym->i -= len;
	while (len--)
		str[num++] = format[sym->i++];
	return (str);
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
	sym->minus ? sym->zero = 0 : 0;
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
		while (format[sym.i] == '%')
		{
			sym.i++;
			if (format[sym.i] == '\0')
				break ;
			missing_flags(format, &sym);
			checking_sizes(format, &sym);
            detect_sign(arg, &format[sym.i++], &sym);
            if (!sym.crutch)
            	sym.i--;
            initializer(&sym);
            system("leaks -q a.out");
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
