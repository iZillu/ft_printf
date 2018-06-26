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

int			ft_printf(const char *format, ...);
char		*itoa_base(unsigned int n, int base, int upper);
void		ft_putchar(char c);
char		*ft_itoa(int n);
void		ft_putnbr(intmax_t n);
size_t		ft_strlen(const char *s);
void		ft_putstr(char const *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);

#endif
