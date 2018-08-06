/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_S_D_o_O_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 05:20:24 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/27 05:20:25 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_S(va_list arg, wchar_t *S, t_sym *sym)
{
	char	*u_code;

	S = va_arg(arg, wchar_t *);
	u_code = ft_strnew(0);
	if (S)
		while (*S)
			u_code = ft_strjoin_free(u_code, ft_putchar_unicode(*S++, sym), 1, 1);
	if (!sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	ft_putstr(u_code);
	if (sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	return (sym->arg_len + sym->check);
}

size_t	print_D(va_list arg, long int *D, t_sym *sym)
{
	*D = va_arg(arg, long int);
 //    sym->save_width = sym->width;
 //    sym->save_precision = sym->precision;
 //    sym->arg_len = ft_strlen_int(*D);
 //    print_space_d(D, sym);
	// if (sym->precision < sym->width && sym->width && sym->precision)
	// 	sym->width = sym->width - sym->precision + sym->arg_len;
	// if (sym->sign == 1 && *D >= 0)
	// 	sym->arg_len++;
	// print_zero_d(D, sym);
 //    if (sym->minus == 0)
 //    	print_width_d(D, sym);
 //    if (sym->sign == 1 && *D >= 0 && !sym->zero)
 //    	print_plus_d(sym);
 //    print_precision_d(D, sym);
	// if (sym->sign == 2 && *D < 0)
	// 	sym->check--;
	// if (sym->dot && !sym->precision && *D == 0 && sym->save_width)
	// 	write(1, " ", 1);
	// else if (!(sym->dot && !sym->precision && *D == 0))
	// 	ft_putnbr(*D);
	// else
	// 	sym->check--;
	// if (sym->minus == 1)
	// 	print_width_d(D, sym);
	return (sym->arg_len + sym->check);
}

size_t	print_o(va_list arg, unsigned int *o, t_sym *sym)
{
	char	*str;

	*o = va_arg(arg, unsigned int);
    sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *o != 0)
		str = ft_strjoin_free("0", (ft_itoa_base(*o , 8, 0)), 0, 0);
	else
		str = ft_itoa_base(*o, 8, 0);
	if (sym->dot && !sym->precision && *o == 0)
		str = NULL;
	sym->arg_len = ft_strlen(str);
	sym->save_width = sym->width;
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_o(o, sym);
    if (sym->minus == 0)
    	print_width_o(sym);
    print_precision_o(o, sym);
	ft_putstr(str);
	if (sym->minus == 1)
		print_width_o(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_O(va_list arg, unsigned long int *O, t_sym *sym)
{
	size_t	len;
	char	*str;

	len = 0;
	*O = va_arg(arg, unsigned long int);
	if (sym->sharp == 0)
		str = ft_itoa_base(*O, 8, 0);
	else
		str = ft_strjoin_free("0", (ft_itoa_base(*O , 8, 0)), 0, 0);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_u(va_list arg, unsigned int *u, t_sym *sym)
{
	*u = va_arg(arg, unsigned int);
    sym->save_width = sym->width;
    sym->save_precision = sym->precision;
    sym->arg_len = ft_strlen_int(*u);
    print_space_u(sym);
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_u(sym);
    if (sym->minus == 0)
    	print_width_u(sym);
    print_precision_u(sym);
	if (sym->dot && !sym->precision && *u == 0 && sym->save_width)
		write(1, " ", 1);
	else if (!(sym->dot && !sym->precision && *u == 0))
		ft_putnbr(*u);
	else
		sym->check--;
	if (sym->minus == 1)
		print_width_u(sym);
	return (sym->arg_len + sym->check);
}
