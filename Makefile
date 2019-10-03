# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 22:08:26 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/10/03 21:49:11 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in

VPATH=./

CC=gcc

LIBFT= -L libft/ -lftprintf

IDIR=./libft

INCLUDES= -I$(IDIR)

HEADERS= lem_in.h
SRC= main_lem_in.c lm_reader.c lm_valid.c lm_errors.c 

CFLAGS=-Wall -Wextra -Werror $(INCLUDES)

RM= rm -f

all: $(NAME)

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ) $(HEADERS)
	make -C libft
	@echo "Lem-in:"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all
