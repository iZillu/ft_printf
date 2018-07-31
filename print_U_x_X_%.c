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

size_t	print_U(va_list arg, unsigned long long int *U, t_sym *sym)
{
	*U = va_arg(arg, unsigned long long int);
	sym->check = 0;
    sym->save_width = sym->width;
    sym->save_precision = sym->precision;
    sym->arg_len = ft_strlen_U_int(*U);
    print_space_u(sym);
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_u(sym);
    if (sym->minus == 0)
    	print_width_u(sym);
    print_precision_u(sym);
	if (sym->dot && !sym->precision && *U == 0 && sym->save_width)
		write(1, " ", 1);
	else if (!(sym->dot && !sym->precision && *U == 0))
		ft_putnbr(*U);
	else
		sym->check--;
	if (sym->minus == 1)
		print_width_u(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_x(va_list arg, int *x, t_sym *sym)
{
	char	*str;

	*x = va_arg(arg, int);
	sym->check = 0;
    sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *x != 0)
		str = ft_strjoin("0x", (ft_itoa_base(*x , 16, 0)));
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

size_t	print_X(va_list arg, int *X, t_sym *sym)
{
	char	*str;

	*X = va_arg(arg, int);
	sym->check = 0;
    sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *X != 0)
		str = ft_strjoin("0X", (ft_itoa_base(*X , 16, 1)));
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
