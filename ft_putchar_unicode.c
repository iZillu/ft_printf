/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 04:39:05 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/27 04:48:50 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putchar_unicode(wchar_t c, t_sym *sym)
{
	char 	*ch;
	char	*tmp;
	int		len;

	sym->arg_len += 1;
	ch = (char *)malloc(sizeof(char) * 5);
	tmp = ft_itoa_base((unsigned long long)c, 2, 0);
	len = ft_strlen(tmp);
	if (len <= 7)
		ch[0] = c;
	else if (len <= 11)
	{
		sym->arg_len++;
		ch[0] = 192 | (c >> 6);
		ch[1] = (63 & c) | 128;
	}
	else if (len <= 16)
	{
		sym->arg_len += 2;
		ch[0] = 224 | (c >> 12);
		ch[1] =	(63 & (c >> 6)) | 128;
		ch[2] = (63 & c) | 128;
	}
	else 
	{
		sym->arg_len += 3;
		ch[0] = 240 | (c >> 18);
		ch[1] = 128 | (c >> 12 & 63);
		ch[2] =	(63 & (c >> 6)) | 128;
		ch[3] = (63 & c) | 128;	
	}
	ch[4] = '\0';
	ft_strdel(&tmp);
	return (ch);
}
