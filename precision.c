/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 03:35:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/24 03:35:01 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision(const char *format, t_sym *sym)
{
	char	*str;
	int		len;
	int		num;

	num = 0;
	len = 0;
	while (format[++sym->i] >= '0' && format[sym->i] <= '9')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	sym->i -= len;
	while (len--)
		str[num++] = format[sym->i++];
	return (str);
}

size_t	ft_strlen_int(int num)
{
	size_t	len;
	int 	i;

	i = 1;
	len = 0;
	if (num < 0)
		num *= -1;
	while (i < num)
	{
		i *= 10;
		len++;
	}
	return (len);
}