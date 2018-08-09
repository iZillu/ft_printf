/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 03:35:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/24 03:35:01 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_strlen_int(intmax_t num)
{
	size_t		len;
	intmax_t 	i;

	i = 1;
	len = 0;
	if (num == -2147483648)
		return (10);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
    if ((num <= 9223372036854775807 && num > 999999999999999999) || num < -9223372036854775807)
        return (19);
	if (num == 1 || num == 0)
		return (1 + len);
	while (i < num)
	{
		i *= 10;
		len++;
	}
	return (len);
}

size_t	ft_strlen_u_int(uintmax_t num)
{
	size_t		len;
	uintmax_t	i;

	i = 1;
	len = 0;
	if (num == 1 || num == 0)
		return (1 + len);
	if (num > 999999999999999999)
        return (20);
	while (i < num)
	{
		i *= 10;
		len++;
	}
	return (len);
}

// 18446744073709551481

void initializer(t_sym *sym)
{
	sym->sign = 0;
	sym->len = 0;
	sym->sharp = 0;
	sym->minus = 0;
	sym->zero = 0;
	sym->dot = 0;
	sym->check = 0;
	sym->width = 0;
	sym->save_width = 0;
	sym->save_precision = 0;
	sym->save_arg_len = 0;
	sym->arg_len = 0;
	sym->size = 0;
	sym->precision = 0;
}