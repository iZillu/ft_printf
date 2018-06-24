# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 05:04:27 by hmuravch          #+#    #+#              #
#    Updated: 2018/06/24 05:17:48 by hmuravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
		itoa_base.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_putnbr.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_strdup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all