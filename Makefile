#******************************************************************************#                                                                
#                                                                              #                                                                
#                                                         :::      ::::::::    #                                                                
#    Makefile                                           :+:      :+:    :+:    #                                                                
#                                                     +:+ +:+         +:+      #                                                                
#    By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+         #                                                                
#                                                 +#+#+#+#+#+   +#+            #                                                                
#    Created: 2017/03/01 13:38:47 by apoplavs          #+#    #+#              #                                                                
#    Updated: 2017/04/21 10:13:51 by apoplavs         ###   ########.fr        #
#                                                                              #                                                                
#******************************************************************************#                                                                

NAME = filler

CC = gcc

LIBFT = libftprintf/libftprintf.a

SRC = main_filler.c get_next_line.c\
set_info.c read_info.c

OBJ = $(SRC:.c=.o)

HEADERS = libftprintf/ft_printf.h filler.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C libftprintf/

libft_clean:
	make -C libftprintf/ clean

libft_fclean:
	make -C libftprintf/ fclean

clean: libft_clean
	rm -f $(OBJ) filler.h.gch get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
