cmake_minimum_required(VERSION 3.9)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf
        ft_itoa.c
        ft_printf.c
        ft_printf.h
        ft_putchar.c
        ft_putnbr.c
        ft_putstr.c
        ft_strdup.c
        ft_strjoin.c
        ft_strlen.c
        itoa_base.c
        main.c)
