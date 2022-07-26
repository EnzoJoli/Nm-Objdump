##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##  makefile
##

SRC 	= 	src/main.c	\
		src/utils.c	\
		src/low_bit.c	\
		src/flag_f.c	\
		src/print.c


CC	=	gcc

NAME	=	../my_objdump

all :		$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) -Wall -Wextra

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean
