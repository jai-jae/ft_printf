# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/22 07:12:15 by jaelee            #+#    #+#              #
#    Updated: 2019/01/10 17:14:54 by jaelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./ft_printf.c \
	  ./get_flags.c \
	  ./print_process_nbr.c \
	  ./print_process_base.c \
	  ./print_process_ptr.c \
	  ./print_process_char.c \
	  ./print_process_str.c \
	  ./print_process_float.c \
	  ./print_float_util.c \
	  ./print_float_error.c \
	  ./process_conv.c \
	  ./process_conv2.c \
	  ./base_conversion.c \
	  ./ltoa_duo.c \
	  ./lltoa_duo.c \
	  ./ultoa_duo.c \
	  ./ulltoa_duo.c \
	  ./init_args.c \
	  ./bigint.c \
	  ./bigint_addition.c \
	  ./bigint_multiplication.c \
	  ./bigint_shift.c \
	  ./double_dabble.c \
	  ./float_error.c \
	  ./process_output.c \
	  ./ft_ftoa.c \
	  ./ft_memcpy.c \
	  ./ft_memalloc.c \
	  ./ft_strlen.c \
	  ./ft_strsub.c \
	  ./ft_strdup.c \
	  ./ft_strjoin.c \
	  ./ft_strnew.c \
	  ./ft_bzero.c \
	  ./ft_memset.c \
	  ./ft_atoi.c \
	  ./ft_itoa.c \
	  ./ft_uitoa.c \
	  ./ft_itoa_base.c \
	  ./ft_uitoa_base.c \
	  ./ft_strlower.c \
	  ./ft_strupper.c \
	  ./ft_strchr.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
INCLUDES = -Iincludes

.SUFFIXES : .c .o
.PHONY : clean

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^
	ranlib $@

$(OBJS): %.o : %.c includes/bigint.h includes/fpoint.h \
					includes/ft_printf.h includes/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean
	make all
