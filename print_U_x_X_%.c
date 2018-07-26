/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_U_x_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:11:52 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/27 06:11:55 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_U(va_list arg, unsigned long int *U)
{
	size_t	len;

	len = 0;
	*U = va_arg(arg, unsigned long int);
	if (*U)
		len = ft_putnbr(*U);
	return (len);
}

size_t	print_x(va_list arg, long long int *x, t_sym *sym)
{
	size_t	len;
	char	*str;

	len = 0;
	*x = va_arg(arg, long long int);
	if (sym->sharp == 0)
		str = itoa_base(*x, 16, 0);
	else
		str = ft_strjoin("0x", (itoa_base(*x , 16, 0)));
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_X(va_list arg, long long int *X, t_sym *sym)
{
	size_t	len;
	char	*str;

	len = 0;
	*X = va_arg(arg, long long int);
	if (sym->sharp == 0)
		str = itoa_base(*X, 16, 1);
	else
		str = ft_strjoin("0X", (itoa_base(*X , 16, 1)));
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_percent()
{
	write(1, "%", 1);
	return (1);
}