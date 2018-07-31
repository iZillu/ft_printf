/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_C_s_c_d_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 05:20:12 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/27 00:18:27 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_i_or_d(va_list arg, t_sym *sym, int *d)
{	
	*d = va_arg(arg, int);
	sym->check = 0;
    sym->save_width = sym->width;
    sym->save_precision = sym->precision;
    sym->arg_len = ft_strlen_int(*d);
    print_space_d(d, sym);
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	if (sym->sign == 1 && *d >= 0)
		sym->arg_len++;
	print_zero_d(d, sym);
    if (sym->minus == 0)
    	print_width_d(d, sym);
    if (sym->sign == 1 && *d >= 0 && !sym->zero)
    	print_plus_d(sym);
    print_precision_d(d, sym);
	if (sym->sign == 2 && *d < 0)
		sym->check--;
	if (sym->dot && !sym->precision && *d == 0 && sym->save_width)
		write(1, " ", 1);
	else if (!(sym->dot && !sym->precision && *d == 0))
		ft_putnbr(*d);
	else
		sym->check--;
	if (sym->minus == 1)
		print_width_d(d, sym);
	return (sym->arg_len + sym->check);
}

size_t	print_s(va_list arg, t_sym *sym, char *s)
{
	s = va_arg(arg, char *);
	sym->check = 0;
	if (!s)
		s = "(null)";
	sym->arg_len = ft_strlen(s);
	if (sym->precision < sym->arg_len && sym->precision)
		sym->arg_len = sym->precision;
	sym->save_arg_len = sym->arg_len;
    if (sym->minus == 0)
    	while (sym->width > sym->arg_len)
    	{
    		write(1, " ", 1);
    		sym->width--;
    		sym->check++;
    	}
    while (sym->arg_len--)
    	write(1, s++, 1);
	if (sym->minus == 1)
		while (sym->width > sym->save_arg_len)
    	{
    		write(1, " ", 1);
    		sym->width--;
    		sym->check++;
    	}
	return (sym->save_arg_len + sym->check);
}

size_t	print_p(va_list arg, unsigned long long *p)
{
	size_t	len;
	char	*str;

	len = 0;
	*p = va_arg(arg, unsigned long long);
	str = ft_strjoin("0x", (ft_itoa_base(*p , 16, 0)));
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_C(va_list arg, wint_t *C)
{
	size_t	len;

	len = 0;
	*C = va_arg(arg, wint_t);
	if (C)
		len += ft_putchar_unicod(*C);
	return (len);
}

size_t	print_c(va_list arg, char *c)
{
	size_t	len;

	len = 0;
	*c = (char)va_arg(arg, int);
	if (c)
	{
		ft_putchar(*c);
		len++;
	}
	return (len);
}
