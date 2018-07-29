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
    int 	check;
    size_t	arg_len;
    size_t	s_width;
    size_t	s_precision;

    check = 0;
    s_width = sym->width;
    s_precision = sym->precision;
    *d = va_arg(arg, int);
    arg_len = ft_strlen_int(*d);
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + ft_strlen_int(*d);
	if (sym->sign == 2 && *d > 0 && !sym->width)
	{
		ft_putchar(' ');
		check++;
	}
	if (sym->sign == 2 && sym->minus == 1)
	{
		write(1, " ", 1);
		arg_len++;
	}
	if (sym->sign == 1 && *d >= 0)
		arg_len++;
    if (sym->zero && !sym->precision)
    {
    	if (sym->sign == 1 && *d >= 0)
    		write(1, "+", 1);
    	while ((sym->width) > arg_len)
    	{
    		write(1, "0", 1);
    		check++;
    		sym->width--;
    	}
    }
    else if (sym->minus == 0)
    {
	   	if (s_width > sym->precision && sym->width > arg_len
		&& sym->precision > arg_len)
	   		while (sym->width > arg_len)
	   		{
	   		  	write(1, " ", 1);
	   		  	check++;
	   		  	sym->width--;
	   		}
	   	else if (s_width > sym->precision && sym->width > arg_len)
	   		while (s_width > arg_len)
	   		{
	   			write(1, " ", 1);
	   			check++;
	   			s_width--;
	   		}
	}
    if (!sym->zero && sym->sign == 1)
    {
        write(1, "+", 1);
        check++;
        arg_len--;
    }
    while ((sym->precision) > arg_len)
    	{
            write(1, "0", 1);
            check++;
            sym->precision--;
    	}
	if (sym->sign == 2 && *d < 0)
		check--;
	ft_putnbr(*d);
	if (sym->minus == 1)
	{
		if (s_width > s_precision && sym->width > arg_len
			&& s_precision > arg_len)
	    	while (sym->width > arg_len)
	    	{
	    	  	write(1, " ", 1);
	    	  	check++;
	    	  	sym->width--;
	    	}
	    else if (s_width > s_precision && sym->width > arg_len)
	    	while (s_width > arg_len)
	    	{
	    		write(1, " ", 1);
	    		check++;
	    		s_width--;
	    	}
	}
	return (arg_len + check);
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
