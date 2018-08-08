/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_U_x_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:11:52 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/30 06:19:05 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_U(va_list arg, uintmax_t *U, t_sym *sym)
{
	if (sym->size < 3)
		sym->size = 3;
	return (print_u(arg, U, sym));
}

size_t	print_x(va_list arg, intmax_t *x, t_sym *sym)
{
	char	*str;

	*x = cast_uint(arg, sym);
    sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *x != 0)
		str = ft_strjoin_free("0x", (ft_itoa_base(*x , 16, 0)), 0, 0);
	else
		str = ft_itoa_base(*x, 16, 0);
	if (sym->dot && !sym->precision && *x == 0)
		str = NULL;
	sym->arg_len = ft_strlen(str);
	if (((sym->sharp == 1 && sym->precision) || (sym->sharp == 1 && sym->zero))
		&& sym->width)
		sym->width -= 2;
	sym->save_width = sym->width;
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_x(x, sym);
    if (sym->minus == 0)
    	print_width_x(sym);
    print_precision_x(x, sym);
	ft_putstr(str);
	if (sym->minus == 1)
		print_width_x(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_X(va_list arg, intmax_t *X, t_sym *sym)
{
	char	*str;

	*X = cast_uint(arg, sym);
    sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *X != 0)
		str = ft_strjoin_free("0X", (ft_itoa_base(*X , 16, 1)), 0, 0);
	else
		str = ft_itoa_base(*X, 16, 1);
	if (sym->dot && !sym->precision && *X == 0)
		str = NULL;
	sym->arg_len = ft_strlen(str);
	if (((sym->sharp == 1 && sym->precision) || (sym->sharp == 1 && sym->zero))
		&& sym->width)
		sym->width -= 2;
	sym->save_width = sym->width;
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_x(X, sym);
    if (sym->minus == 0)
    	print_width_x(sym);
    print_precision_x(X, sym);
	ft_putstr(str);
	if (sym->minus == 1)
		print_width_x(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_percent(t_sym *sym)
{
	int check;

	check = 1;
	if (sym->minus == 1)
		write(1, "%", 1);
	while (sym->width-- > 1)
	{
		if (sym->zero == 0)
			write(1, " ", 1);
		else
			write (1, "0", 1);
		check++;
	}
	if (sym->minus == 0)
		write(1, "%", 1);
	return (check);
}
