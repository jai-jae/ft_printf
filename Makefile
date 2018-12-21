# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 16:34:17 by jaelee            #+#    #+#              #
#    Updated: 2018/12/20 06:54:48 by jaelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

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
	  ./bigint/bigint.c \
	  ./bigint/bigint_addition.c \
	  ./bigint/bigint_multiplication.c \
	  ./bigint/bigint_shift.c \
	  ./bigint/double_dabble.c \
	  ./bigint/float_error.c \
	  ./bigint/process_output.c \
	  ./bigint/ft_ftoa.c

OBJ = $(SRC:.c=.o)
HEADER = -Iincludes -Ilibft/

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	gcc -Llibft -lft $^ -o $@

%.o : %.c
	gcc $(HEADER) -c $^ -o $@

libft/libft.a :
	make -C libft

clean :
	make -C libft clean
	rm -f $(OBJ)

fclean : clean
	make -C libft libclean
	rm -f $(NAME)

re: fclean
	make all
