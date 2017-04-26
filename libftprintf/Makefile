#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 13:38:47 by apoplavs          #+#    #+#              #
#    Updated: 2017/03/01 13:38:49 by apoplavs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc

LIB_PATH = ./libft/

LIB = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o\
 ft_isascii.o ft_isdigit.o ft_islower.o ft_isprint.o\
 ft_isupper.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o\
 ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o\
 ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o\
 ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o\
 ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o\
 ft_putstr.o ft_putstr_fd.o ft_sort_tab.o ft_strcat.o\
 ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o\
 ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o\
 ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o\
 ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o\
 ft_strrchr.o ft_strrev.o ft_strsplit.o ft_strstr.o ft_strsub.o\
 ft_strtrim.o ft_swap.o ft_tolower.o ft_toupper.o

SRC_NAME = converter_base.o final_write.o ft_printf.o initialize_flags.o\
 type_char.o type_dec.o type_oct.o type_str.o type_hex.o type_float.o

SRC_LIB = $(addprefix $(LIB_PATH), $(LIB))

OBJ = $(SRC_LIB) $(SRC_NAME)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIB): %.o: $(LIB_PATH)%.c
	@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@

$(SRC_NAME): %.o: %.c
	@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@

clean:
	rm -f $(OBJ) ft_printf.h.gch $(LIB_PATH)libft.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all