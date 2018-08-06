/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:21:24 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/24 18:21:19 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_free(char *s1, char *s2, int first, int second)
{
	char	*str;
	int		len;
	int		i;
	int		x;

	if (s1 && s2)
	{
		i = 0;
		x = 0;
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[x] != '\0')
			str[i++] = s2[x++];
		str[i] = '\0';
		if (first)
			ft_strdel(&s1);
		if (second)
			ft_strdel(&s2);
		return (str);
	}
	return (NULL);
}
