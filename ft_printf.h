/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 05:09:41 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/24 10:03:57 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>


# define PROTECT(x) if (!x) return (-1)

typedef	struct	s_type
{
	int				x;
	char			*str;
	wchar_t			*S;
}				t_type;

int		ft_printf(const char *format, ...);
char		*ft_itoa_base(intmax_t n, int base, int lower);

#endif
