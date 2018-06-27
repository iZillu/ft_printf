/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 01:15:43 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/12 22:17:05 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(intmax_t n)
{
	intmax_t		num;
	intmax_t		i;
	intmax_t		r;
	size_t			len;

	len = 0;
	num = 1;
	r = n;
	i = 1;
	if (n < 0)
	{
		ft_putchar('-');
		r = n * -1;
		len++;
	}
	while ((r / i) > 9)
		i *= 10;
	while (i > 0 && ++len)
	{
		num = r / i;
		r = r % i;
		ft_putchar((char)num + '0');
		i /= 10;
	}
	return (len);
}
