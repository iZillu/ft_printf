/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:26:04 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/06 15:26:13 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	cast_int(va_list arg, t_sym *sym)
{
	if (sym->size == 1)
		return ((char)va_arg(arg, int));
	else if (sym->size == 2)
		return ((short)va_arg(arg, int));
	else if (sym->size == 3)
		return (va_arg(arg, long int));
	else if (sym->size == 4)
		return (va_arg(arg, long long int));
	else if (sym->size == 5)
		return (va_arg(arg, intmax_t));
	else if (sym->size == 6)
		return (va_arg(arg, ssize_t));
	else
		return (va_arg(arg, int));
}

intmax_t	cast_uint(va_list arg, t_sym *sym)
{
	if (sym->size == 1)
		return ((unsigned char)va_arg(arg, int));
	else if (sym->size == 2)
		return ((unsigned short)va_arg(arg, int));
	else if (sym->size == 3)
		return (va_arg(arg,unsigned long int));
	else if (sym->size == 4)
		return (va_arg(arg,unsigned long long int));
	else if (sym->size == 5)
		return (va_arg(arg, uintmax_t));
	else if (sym->size == 6)
		return (va_arg(arg, size_t));
	else
		return (va_arg(arg, unsigned int));
}
