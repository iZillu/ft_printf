/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 04:39:05 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/27 04:48:50 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_unicod(wchar_t c)
{
	char 	ch[4];
	size_t	size;
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
	return (size);
}
