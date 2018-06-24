/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:23:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/24 05:23:02 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar_uni(wchar_t c)
{
	char 	ch[4];
	int		size;
	int		len;

	size = 1;
	len = ft_strlen(ft_itoa_base((unsigned long long)c, 2, 0));
	if (len <= 7)
		ch[0] = c;
	else if (len <= 11)
	{
		size++;
		ch[0] = 192 | (c >> 6);
		ch[1] = (63 & c) | 128;
	}
	else if (len <= 16)
	{
		size += 2;
		ch[0] = 224 | (c >> 12);
		ch[1] =	(63 & (c >> 6)) | 128;
		ch[2] = (63 & c) | 128;
	}
	else 
	{
		size += 3;
		ch[0] = 240 | (c >> 18);
		ch[1] = 128 | (c >> 12 & 63);
		ch[2] =	(63 & (c >> 6)) | 128;
		ch[3] = (63 & c) | 128;	
	}
	write(1, &ch, size);
}

void	detect_sign(va_list arg, const char *format)
{
	t_type	type;

	
	if (*format == 's')
		ft_putstr(va_arg(arg, char *));
	else if (*format == 'i' || *format == 'd')
		ft_putnbr(va_arg(arg, int));
	else if (*format == '%')
		write(1, "%", 1);
	else if (*format == 'p')
		ft_putstr(ft_strjoin("0x",
			(ft_itoa_base(va_arg(arg, unsigned long long), 16, 0))));
	else if (*format == 'C')
		ft_putchar_uni(va_arg(arg, wint_t));
	else if (*format == 'c')
		ft_putchar((char)va_arg(arg, int));
	else if (*format == 'S' && (type.S = va_arg(arg, wchar_t *)))
		while (*type.S)
			ft_putchar_uni(*type.S++);
	else if (*format == 'D')
		ft_putnbr(va_arg(arg, long int));
	else if (*format == 'o')
		ft_putstr(ft_itoa_base(va_arg(arg, int), 8, 0));
	else if (*format == 'O')
		ft_putstr(ft_itoa_base(va_arg(arg, long int), 8, 0));
	else if (*format == 'u')
		ft_putnbr(va_arg(arg, long int));
	else if (*format == 'U')
		ft_putnbr(va_arg(arg, unsigned long int));
	else if (*format == 'x')
		ft_putstr(ft_itoa_base(va_arg(arg, int), 16, 0));
	else if (*format == 'X')
		ft_putstr(ft_itoa_base(va_arg(arg, int), 16, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, format);
	i = -1;
	while (format[++i])
	{
		while(format[i] == '%')
		{
			i++;
			detect_sign(arg, &format[i++]);
			va_end (arg);
		}
		write(1, &format[i], 1);
	}
	return (1);
}