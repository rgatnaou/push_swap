# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 16:12:26 by rgatnaou          #+#    #+#              #
#    Updated: 2022/03/29 14:41:29 by rgatnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = check_arg.c utils.c split.c list.c\
		main.c sort_list.c rr.c rrr.c ss.c pa_pb.c

SRC_B = checker_f/check_arg.c checker_f/utils.c checker_f/split.c \
		checker_f/rr.c checker_f/rrr.c checker_f/ss.c checker_f/list.c\
		checker_f/pa_pb.c checker_f/checker.c checker_f/get_next_line.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

NAME = push_swap

NAME_B = checker

HEADER = push_swap.h

HEADER_B = checker_f/checker.h

all : $(NAME)

$(NAME) : $(HEADER) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus : $(HEADER_B) $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_B)
	
%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ 

clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all