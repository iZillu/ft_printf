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
    size_t	s_width;

    s_width = sym->width;
    check = 0;
	*d = va_arg(arg, int);
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + ft_strlen_int(*d);
	if (sym->sign == 2 && *d > 0 && sym->width == 0)
	{
		ft_putchar(' ');
		check++;
	}
	if (*d < 0)
		ft_putchar('-');
	if (sym->sign == 1 && *d > 0)
    {
        ft_putchar('+');
        check++;
    }
    if (sym->zero && !sym->precision)
    	while ((sym->width) > ft_strlen_int(*d))
    	{
    		write(1, "0", 1);
    		check++;
    		sym->width--;
    	}
    else if (s_width > sym->precision && sym->width > ft_strlen_int(*d)
    	&& sym->precision > ft_strlen_int(*d))
    	while ((sym->width) > ft_strlen_int(*d))
    	{
    	  	write(1, " ", 1);
    	  	check++;
    	  	sym->width--;
    	}
    else if (s_width > sym->precision && sym->width > ft_strlen_int(*d))
    	while (s_width > ft_strlen_int(*d))
    	{
    		write(1, " ", 1);
    		check++;
    		s_width--;
    	}
    while ((sym->precision) > ft_strlen_int(*d))
    	{
            write(1, "0", 1);
            check++;
            sym->precision--;
    	}
	if (sym->sign == 2 && *d < 0)
		check--;
	ft_putnbr(*d);
	return (ft_strlen_int(*d) + check);
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
