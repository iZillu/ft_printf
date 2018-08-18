/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 05:09:41 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/16 07:13:44 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>

# define MIN_INT	-9223372036854775807 - 1

typedef	struct		s_type
{
	void			*p;
	char			*s;
	wchar_t			*cap_s;
	char			c;
	wint_t			cap_c;
	intmax_t		d;
	intmax_t		cap_d;
	intmax_t		x;
	intmax_t		cap_x;
	uintmax_t		o;
	uintmax_t		cap_o;
	uintmax_t		u;
	uintmax_t		cap_u;
}					t_type;

typedef	struct		s_sym
{
	int				i;
	int				sign;
	int				len;
	int				sharp;
	int				minus;
	int				zero;
	int				size;
	int				dot;
	int				check;
	char			*tmp;
	char			*tmp2;
	size_t			bits;
	size_t			crutch;
	size_t			width;
	size_t			save_width;
	size_t			save_precision;
	size_t			save_arg_len;
	size_t			arg_len;
	size_t			precision;
}					t_sym;

int					ft_printf(const char *format, ...);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(intmax_t n);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *add);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_putchar_unicode(wchar_t c, t_sym *sym);
char				*ft_precision(const char *format, t_sym *sym);
char				*ft_itoa_base(uintmax_t num, int base, int upper);
char				*ft_strjoin_free(char *s1, char *s2, int first, int second);
char				*ft_take_number(const char *format, t_sym *sym);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_strdel(char **as);
void				ft_putnbr(intmax_t n);
void				initializer(t_sym *sym);
void				ft_putnbr_u(uintmax_t n);
void				ft_putstr(char const *s);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_atoi(const char *str);
size_t				ft_strlen_int(intmax_t num);
size_t				ft_strlen_u_int(uintmax_t num);
size_t				print_s(va_list arg, t_sym *sym, char *s);
size_t				print_cap_s(va_list arg, wchar_t *cap_s, t_sym *sym);
size_t				print_i_or_d(va_list arg, t_sym *sym, intmax_t *d);
size_t				print_cap_d(va_list arg, intmax_t *cap_d, t_sym *sym);
size_t				print_p(va_list arg, void *p, t_sym *sym);
size_t				print_c(va_list arg, char *c, t_sym *sym);
size_t				print_cap_c(va_list arg, wint_t *cap_c, t_sym *sym);
size_t				print_o(va_list arg, uintmax_t *cap_o, t_sym *sym);
size_t				print_cap_o(va_list arg, uintmax_t *cap_o, t_sym *sym);
size_t				print_u(va_list arg, uintmax_t *u, t_sym *sym);
size_t				print_cap_u(va_list arg, uintmax_t *cap_u, t_sym *sym);
size_t				print_x(va_list arg, intmax_t *x, t_sym *sym);
size_t				print_cap_x(va_list arg, intmax_t *cap_x, t_sym *sym);
size_t				print_percent(t_sym *sym);
void				missing_width_and_precision(const char *format, t_sym *sym);
void				missing_flags(const char *format, t_sym *sym);
void				checking_sizes(const char *format, t_sym *sym);
void				print_plus_d(t_sym *sym);
void				print_width_d(intmax_t *d, t_sym *sym);
void				print_space_d(intmax_t *d, t_sym *sym);
void				print_zero_d(intmax_t *d, t_sym *sym);
void				print_precision_d(intmax_t *d, t_sym *sym);
void				print_zero_x(intmax_t *x, t_sym *sym);
void				print_precision_x(intmax_t *x, t_sym *sym);
void				print_width_x(t_sym *sym);
void				print_space_u(t_sym *sym);
void				print_zero_u(t_sym *sym);
void				print_width_u(t_sym *sym);
void				print_precision_u(t_sym *sym);
void				print_zero_o(uintmax_t *o, t_sym *sym);
void				print_width_o(t_sym *sym);
void				print_precision_o(uintmax_t *o, t_sym *sym);
void				print_width_not_minus_cap_s(t_sym *sym);
void				print_width_yes_minus_cap_s(t_sym *sym);
intmax_t			cast_int(va_list arg, t_sym *sym);
intmax_t			cast_uint(va_list arg, t_sym *sym);

#endif
