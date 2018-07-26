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
# include <stdio.h>

# define PROTECT(x) if (!x) return (-1)

typedef	struct			s_type
{
	char				*s;
	wchar_t				*S;
	unsigned long long 	p;
	wint_t				C;
	char 				c;
	long int 			D;
	unsigned int 		o;
	unsigned long int 	O;
	long int 			u;
	unsigned long int 	U;
	long long int 		x;
	long long int 		X;
	int 				d;
}						t_type;

typedef	struct			s_sym
{
	int 				i;
	int 				sign;
	size_t				bits;
	int 				len;
	int 				sharp;
	int 				minus;
	int 				zero;
	size_t				width;
	size_t 				precision;
}						t_sym;

int		ft_printf(const char *format, ...);
char	*itoa_base(uintmax_t n, int base, int upper);
void	ft_putchar(char c);
char	*ft_itoa(intmax_t n);
size_t	ft_putnbr(intmax_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	print_s(va_list arg, t_sym *sym, char *s);
size_t	print_i_or_d(va_list arg, t_sym *sym, int *d);
size_t	print_p(va_list arg, unsigned long long *p);
size_t	print_C(va_list arg, wint_t *C);
size_t	ft_putchar_unicod(wchar_t c);
size_t	print_c(va_list arg, char *c);
size_t	print_S(va_list arg, wchar_t *S);
size_t	print_D(va_list arg, long int *D);
size_t	print_o(va_list arg, unsigned int *o, t_sym *sym);
size_t	print_O(va_list arg, unsigned long int *O, t_sym *sym);
size_t	print_u(va_list arg, long int *u);
size_t	print_U(va_list arg, unsigned long int *U);
size_t	print_x(va_list arg, long long int *x, t_sym *sym);
size_t	print_X(va_list arg, long long int *X, t_sym *sym);
size_t	print_percent();
char	*precision(const char *format, t_sym *sym);
size_t	ft_strlen_int(int num);

#endif
