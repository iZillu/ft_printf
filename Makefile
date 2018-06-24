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

NOC = \x1b[0m
OKC = \x1b[32m
ERC = \x1b[31m
WAC = \x1b[33m

CFLAGS += -Wall -Wextra -Werror

CFLAGS += -I includes/

FILES = ft_printf.c \
		ft_itoa_base.c

LIBFILES =	ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strlen.c

LIBSRCS	= $(addprefix libft/, $(LIBFILES))

OBJ = $(PRINTFSRCS:.c=.o)

LIBOBJ = $(LIBSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo "$(WAC)PRINTF:\tObject was created$(NOC)"

$(LIBOBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(LIBOBJ) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBOBJ)
	@echo "$(OKC)PRINTF:\tPrint it, Baby$(NOC)"

clean:
	@rm -f $(OBJ) $(LIBOBJ)
	@echo "$(ERC)PRINTF:\tObjects were deleted$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(ERC)PRINTF:\tFillit was deleted$(NOC)"

re: fclean all