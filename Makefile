# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 16:12:26 by rgatnaou          #+#    #+#              #
#    Updated: 2022/04/10 23:21:59 by rgatnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = check_arg.c utils.c split.c list.c\
		push_swap.c sort_list.c rr.c rrr.c ss.c pa_pb.c

SRC_B = bonus/check_arg.c bonus/utils.c bonus/split.c \
		bonus/rr.c bonus/rrr.c bonus/ss.c bonus/list.c\
		bonus/pa_pb.c bonus/checker.c bonus/get_next_line.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

NAME = push_swap

NAME_B = checker

HEADER = push_swap.h

HEADER_B = bonus/checker.h

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