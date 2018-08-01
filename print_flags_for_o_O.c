/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_for_o_O.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:21:57 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/31 07:21:59 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_zero_o(unsigned int *x, t_sym *sym)
{
	if (sym->zero && !sym->precision)
    {
    	if (sym->sharp == 1 && *x != 0)
    	{
    		write(1, "0", 1);
    		sym->check++;
    		sym->precision--;
    	}
    	while (sym->width > sym->arg_len)
    	{
    		write(1, "0", 1);
    		sym->check++;
    		sym->width--;
    	}
    }
}

void print_width_o(t_sym *sym)
{
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

void print_precision_o(unsigned int *x, t_sym *sym)
{
	if ((sym->sharp == 1 && sym->precision && *x != 0))
	{
		write(1, "0", 1);
		sym->check++;
		sym->precision--;
	}
	if ((sym->sharp == 1 && !sym->precision && *x == 0))
	{
		write(1, "0", 1);
		// sym->check++;
	}
	while (sym->precision > sym->arg_len)
    	{
            write(1, "0", 1);
            sym->check++;
            sym->precision--;
    	}
}

