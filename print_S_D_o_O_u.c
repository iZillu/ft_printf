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
	char	*tmp;
	char	*tmp2;

	S = va_arg(arg, wchar_t *);
	u_code = ft_strnew(0);
	if (S)
		while (*S)
		{
			tmp = ft_strdup(u_code);
			tmp2 = ft_putchar_unicode(*S++, sym);
			ft_strdel(&u_code);
			u_code = ft_strjoin_free(tmp, tmp2, 1, 1);
		}
	else
	{
		u_code = "(null)";
		sym->arg_len = 6;
	}
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

size_t	print_D(va_list arg, intmax_t *D, t_sym *sym)
{
	if (sym->size < 3)
		sym->size = 3;
	return (print_i_or_d(arg, sym, D));
}

size_t	print_o(va_list arg, uintmax_t *o, t_sym *sym)
{
	char	*str;

	*o = cast_uint(arg, sym);;
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

size_t	print_O(va_list arg, uintmax_t *O, t_sym *sym)
{
	if (sym->size < 3)
		sym->size = 3;
	return (print_o(arg, O, sym));
}

size_t	print_u(va_list arg, uintmax_t *u, t_sym *sym)
{
	*u = cast_uint(arg, sym);
    sym->save_width = sym->width;
    sym->save_precision = sym->precision;
    sym->arg_len = ft_strlen_u_int(*u);
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
		ft_putnbr_u(*u);
	else
		sym->check--;
	if (sym->minus == 1)
		print_width_u(sym);
	return (sym->arg_len + sym->check);
}
