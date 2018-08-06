# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 05:04:27 by hmuravch          #+#    #+#              #
#    Updated: 2018/08/02 16:02:36 by hmuravch         ###   ########.fr        #
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
		ft_strjoin.c \
		ft_itoa.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_strdel.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_strnew.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_putchar_unicod.c \
		print_flags_for_d_i.c \
		print_flags_for_x_X.c \
		print_flags_for_u_U.c \
		print_flags_for_o_O.c \
		print_S_D_o_O_u.c \
		print_C_s_c_d_p.c \
		print_U_x_X_%.c \
		ft_precision.c

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
