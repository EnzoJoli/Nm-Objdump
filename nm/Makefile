##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##  makefile
##

SRC 	= 	nm.c

CC	=	gcc

NAME	=	../my_nm

all :		$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) -Wall -Wextra

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean
