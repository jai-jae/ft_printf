# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/22 07:12:15 by jaelee            #+#    #+#              #
#    Updated: 2018/12/22 07:55:14 by jaelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./ft_printf.c \
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

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = -Iincludes

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o : %.c
	gcc $(FLAGS) $(HEADER) -c $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean
	make all
