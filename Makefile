# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhote <alhote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 17:05:31 by alhote            #+#    #+#              #
#    Updated: 2016/03/07 17:09:39 by alhote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./
OBJ = $(SRC:.c=.o)
SRC =
HEADER =

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
