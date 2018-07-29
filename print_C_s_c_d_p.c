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

void print_space(int *d, t_sym *sym)
{
	if (sym->sign == 2 && *d > 0 && !sym->width)
	{
		write(1, " ", 1);
		sym->check++;
	}
	if (sym->sign == 2 && sym->minus == 1)
	{
		write(1, " ", 1);
		sym->arg_len++;
	}
}

void print_zero(int *d, t_sym *sym)
{
	if (sym->zero && !sym->precision)
    {
    	if (sym->sign == 1 && *d >= 0)
    		write(1, "+", 1);
    	if (*d < 0)
		{
			write(1, "-", 1);
			*d *= -1;
			sym->arg_len = ft_strlen_int(*d) + 1;
		}
    	while (sym->width > sym->arg_len)
    	{
    		write(1, "0", 1);
    		sym->check++;
    		sym->width--;
    	}
    }
}

void print_width(t_sym *sym, int *d)
{
	if (sym->sign == 1 && *d >= 0 && !sym->zero && sym->width)
	{
		sym->width--;
		sym->save_width--;
	}
	if (*d < 0 && sym->precision)
		sym->save_precision++;
	sym->precision = sym->save_precision;
	if (sym->save_width > sym->precision && sym->width > sym->arg_len
	&& sym->precision > sym->arg_len)
		while (sym->width > sym->arg_len)
		{
		  	write(1, " ", 1);
		  	sym->check++;
		  	sym->width--;
		}
	else if (sym->save_width > sym->precision && sym->width > sym->arg_len)
		while (sym->save_width > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
			sym->save_width--;
		}
}

void print_precision(int *d, t_sym *sym)
{
	if (*d < 0)
	{
		write(1, "-", 1);
		*d *= -1;
		sym->arg_len = ft_strlen_int(*d) + 1;
	}
	while (sym->precision > sym->arg_len)
    	{
            write(1, "0", 1);
            sym->check++;
            sym->precision--;
    	}
	if (sym->sign == 2 && *d < 0)
		sym->check--;
}

void print_plus(t_sym *sym)
{
	write(1, "+", 1);
	sym->check++;
	sym->arg_len--;
}

size_t	print_i_or_d(va_list arg, t_sym *sym, int *d)
{	
	sym->check = 0;
    sym->save_width = sym->width;
    sym->save_precision = sym->precision;
    *d = va_arg(arg, int);
    sym->arg_len = ft_strlen_int(*d);
    print_space(d, sym);
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	if (sym->sign == 1 && *d >= 0)
		sym->arg_len++;
	print_zero(d, sym);
    if (sym->minus == 0)
    	print_width(sym, d);
    if (sym->sign == 1 && *d >= 0 && !sym->zero)
    	print_plus(sym);
    print_precision(d, sym);
	if (sym->sign == 2 && *d < 0)
		sym->check--;
	ft_putnbr(*d);
	if (sym->minus == 1)
		print_width(sym, d);
	return (sym->arg_len + sym->check);
}

size_t	print_s(va_list arg, t_sym *sym, char *s)
{
	size_t	i;
	int 	check;

	i = 0;
	check = 0;
	s = va_arg(arg, char *);
	if (!s)
		s = "(null)";
	while ((sym->width) > ft_strlen(s))
	{
		write(1, " ", 1);
		check++;
		sym->width--;
	}
	if (sym->precision)
	{
		while (i < sym->precision && s[i])
		{
			write(1, &s[i++], 1);
			check--;
		}
		check = -1 * (ft_strlen(s) + check);
	}
	else
		ft_putstr(s);
	return (ft_strlen(s) + check);
}

size_t	print_p(va_list arg, unsigned long long *p)
{
	size_t	len;
	char	*str;

	len = 0;
	*p = va_arg(arg, unsigned long long);
	str = ft_strjoin("0x", (itoa_base(*p , 16, 0)));
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
