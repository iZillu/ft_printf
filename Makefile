# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 05:04:27 by hmuravch          #+#    #+#              #
#    Updated: 2018/08/16 07:35:49 by hmuravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
		ft_itoa_base.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_putnbr.c \
		ft_strjoin_free.c \
		ft_itoa.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_strdel.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_strnew.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncmp.c \
		ft_strlen_int.c \
		my_caster.c \
		my_putchar_unicode.c \
		print_flags_for_i.c \
		print_flags_for_x.c \
		print_flags_for_u.c \
		print_flags_for_o.c \
		print_flags_for_cap_s.c \
		print_s_o.c \
		print_d_c_p.c \
		print_percent_u_x.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar -rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all	
