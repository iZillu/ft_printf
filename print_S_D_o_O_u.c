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

size_t	print_S(va_list arg, wchar_t *S)
{
	size_t	len;

	len = 0;
	S = va_arg(arg, wchar_t *);
	if (S)
		while (*S)
			len += ft_putchar_unicod(*S++);
	return (len);
}

size_t	print_D(va_list arg, long int *D)
{
	size_t	len;

	len = 0;
	*D = va_arg(arg, long int);
	if (*D)
		len = ft_putnbr(*D);
	return (len);
}

size_t	print_o(va_list arg, unsigned int *o, t_sym *sym)
{
	size_t	len;
	char	*str;

	len = 0;
	*o = va_arg(arg, unsigned int);
	if (sym->sharp == 0)
		str = itoa_base(*o, 8, 0);
	else
		str = ft_strjoin("0", (itoa_base(*o , 8, 0)));
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_O(va_list arg, unsigned long int *O, t_sym *sym)
{
	size_t	len;
	char	*str;

	len = 0;
	*O = va_arg(arg, unsigned long int);
	if (sym->sharp == 0)
		str = itoa_base(*O, 8, 0);
	else
		str = ft_strjoin("0", (itoa_base(*O , 8, 0)));
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_u(va_list arg, long int *u)
{
	size_t	len;

	len = 0;
	*u = va_arg(arg, long int);
	if (*u)
		len = ft_putnbr(*u);
	return (len);
}