CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = check_arg.c utils.c split.c list.c linked.c sort.c main.c sort_list.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

HEADER = push_swap.h

all : $(NAME)

$(NAME) : $(HEADER) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ 

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all