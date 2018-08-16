/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_for_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 23:20:33 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/15 10:41:29 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_d(intmax_t *d, t_sym *sym)
{
	if (*d >= 0 && sym->sign == 2)
	{
		write(1, " ", 1);
		sym->width--;
		sym->check++;
	}
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
}

void	print_zero_d(intmax_t *d, t_sym *sym)
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

void	print_width_d(intmax_t *d, t_sym *sym)
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

void	print_precision_d(intmax_t *d, t_sym *sym)
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
}

void	print_plus_d(t_sym *sym)
{
	write(1, "+", 1);
	sym->check++;
	sym->arg_len--;
}
