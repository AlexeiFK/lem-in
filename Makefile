# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 22:08:26 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/10/18 23:06:08 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in

VPATH=./

CC=gcc

LIBFT= -L libft/ -lftprintf

IDIR=./libft

INCLUDES= -I$(IDIR)

HEADERS= lem_in.h

SRC= main_lem_in.c lm_reader.c lm_reader_fill.c lm_reader_fill2.c lm_valid.c lm_valid_comm.c lm_errors.c lm_init.c \
	lm_free.c lm_free2.c lm_reader2.c lm_flow.c ft_queue.c ft_lstadd_l.c ft_bfs.c lm_result.c \
	lm_edm_karp.c lm_split_ants.c lm_print_final.c lm_result_free.c lm_result2.c \
	lm_result3.c lm_edm_karp2.c lm_start_to_end.c lm_print_flag.c

CFLAGS= -Wall -Wextra -Werror $(INCLUDES) -O2 -march=native

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
