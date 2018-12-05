# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 16:34:17 by jaelee            #+#    #+#              #
#    Updated: 2018/12/05 19:34:17 by jaelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

SRC = ./ft_printf.c \
	  ./get_flags.c \
	  ./print_process_nbr.c \
	  ./print_process_base.c \
	  ./process_conv.c \
	  ./base_conversion.c \
	  ./ltoa_duo.c \
	  ./lltoa_duo.c \
	  ./ultoa_duo.c \
	  ./ulltoa_duo.c \
	  ./init_args.c

OBJ = $(SRC:.c=.o)

HEADER = -I ./ -I libft/

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
