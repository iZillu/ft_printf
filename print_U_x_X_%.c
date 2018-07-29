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
	*U = va_arg(arg, unsigned long int);
	if (*U)
		ft_putnbr(*U);
	return (ft_strlen_int(*U));
}

size_t	print_x(va_list arg, int *x, t_sym *sym)
{
	size_t	len;
	char	*str;

	len = 0;
	*x = va_arg(arg, int);
	if (sym->sharp == 1 && *x > 0)
		str = ft_strjoin("0x", (itoa_base(*x , 16, 0)));
	else
		str = itoa_base(*x, 16, 0);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_X(va_list arg, int *X, t_sym *sym)
{
	size_t	len;
	char	*str;

	len = 0;
	*X = va_arg(arg, int);
	if (sym->sharp == 1 && *X > 0)
		str = ft_strjoin("0X", (itoa_base(*X , 16, 1)));
	else
		str = itoa_base(*X, 16, 1);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

size_t	print_percent(t_sym *sym)
{
	int check;

	check = 1;
	if (sym->minus == 1)
		write(1, "%", 1);
	while (sym->width-- > 1)
	{
		if (sym->zero == 0)
			write(1, " ", 1);
		else
			write (1, "0", 1);
		check++;
	}
	if (sym->minus == 0)
		write(1, "%", 1);
	return (check);
}
