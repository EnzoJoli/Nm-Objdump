##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##  makefile
##

nm:
		make -C ./nm
objdump :
		make -C ./objdump
all :
		make -C ./objdump
		make -C ./nm
clean:
		make clean -C ./objdump
		make clean -C ./nm

fclean:
		make fclean -C ./objdump
		make fclean -C ./nm

re:
		make re -C ./objdump
		make re -C ./nm

.PHONY:		objdump
.PHONY:		nm
