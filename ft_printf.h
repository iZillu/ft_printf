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
# define MIN_INT	-9223372036854775807 - 1

typedef	struct			s_type
{
	char					*s;
	wchar_t					*S;
	void 					*p;
	wint_t					C;
	char 					c;
	intmax_t				D;
	uintmax_t	 			o;
	uintmax_t			 	O;
	uintmax_t	 			u;
	uintmax_t 			 	U;
	intmax_t				x;
	intmax_t				X;
	intmax_t				d;
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
	int 				size;
	int 				dot;
	int 				check;
	size_t				width;
	size_t 				save_width;
	size_t 				save_precision;
	size_t 				save_arg_len;
	size_t				arg_len;
	size_t 				precision;
}						t_sym;

int			ft_printf(const char *format, ...);
void 		initializer(t_sym *sym);
char		*ft_itoa_base(uintmax_t num, int base, int upper);
char		*ft_itoa(intmax_t n);
char		*ft_strjoin_free(char *s1, char *s2, int first, int second);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_precision(const char *format, t_sym *sym);
void		ft_putnbr(intmax_t n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		*ft_memalloc(size_t size);
void		ft_strdel(char **as);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlen_int(intmax_t num);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen_U_int(uintmax_t num);
size_t		ft_atoi(const char *str);
char		*ft_strnew(size_t size);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *dst, const char *add);
char		*ft_putchar_unicode(wchar_t c, t_sym *sym);
size_t		print_s(va_list arg, t_sym *sym, char *s);
size_t		print_i_or_d(va_list arg, t_sym *sym, intmax_t *d);
size_t		print_p(va_list arg, void *p, t_sym *sym);
size_t		print_C(va_list arg, wint_t *C, t_sym *sym);
size_t		print_c(va_list arg, char *c, t_sym *sym);
size_t		print_S(va_list arg, wchar_t *S, t_sym *sym);
size_t		print_D(va_list arg, intmax_t *D, t_sym *sym);
size_t		print_o(va_list arg, uintmax_t *O, t_sym *sym);
size_t		print_O(va_list arg, uintmax_t *O, t_sym *sym);
size_t		print_u(va_list arg, uintmax_t *u, t_sym *sym);
size_t		print_U(va_list arg, uintmax_t *U, t_sym *sym);
size_t		print_x(va_list arg, intmax_t *x, t_sym *sym);
size_t		print_X(va_list arg, intmax_t *X, t_sym *sym);
size_t		print_percent();
void 		print_plus_d(t_sym *sym);
void 		print_width_d(intmax_t *d, t_sym *sym);
void 		print_space_d(intmax_t *d, t_sym *sym);
void 		print_zero_d(intmax_t *d, t_sym *sym);
void 		print_precision_d(intmax_t *d, t_sym *sym);
void 		print_zero_x(intmax_t *x, t_sym *sym);
void 		print_precision_x(intmax_t *x, t_sym *sym);
void 		print_width_x(t_sym *sym);
void 		print_space_u(t_sym *sym);
void 		print_zero_u(t_sym *sym);
void 		print_width_u(t_sym *sym);
void 		print_precision_u(t_sym *sym);
void 		print_zero_o(uintmax_t *o, t_sym *sym);
void 		print_width_o(t_sym *sym);
void 		print_precision_o(uintmax_t *o, t_sym *sym);
intmax_t	cast_int(va_list arg, t_sym *sym);
intmax_t	cast_uint(va_list arg, t_sym *sym);

#endif
