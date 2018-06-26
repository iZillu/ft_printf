/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 10:02:53 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/24 12:10:41 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits_base(uintmax_t n, int base)
{
	int		qnt;

	qnt = 0;
	if (n == 0)
		qnt++;
	while (n > 0)
	{
		n /= base;
		qnt++;
	}
	return (qnt);
}

char		*itoa_base(uintmax_t n, int base, int upper)
{
	char	*str;
	int		i;

	str = 0;
	if (base == 10)
		return (ft_itoa(n));
	i = ft_count_digits_base(n, base) + 1;
	if (!(str = (char *)malloc(i)))
		return (str);
	str[--i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (i-- > 0)
	{
		if (n % base <= 9)
			str[i] = n % base + '0';
		else if (upper == 0)
			str[i] = n % base + 87;
		else
			str[i] = n % base + 55;
		n /= base;
	}
	return (str);
}
