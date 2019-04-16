##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC	=	main.c	\
		main_two.c	\
		main_three.c	\
		main_four.c	\
		main_five.c	\
		main_six.c	\
		main_seven.c	\
		main_eigth.c	\
		setenv.c	\
		setenv_two.c	\
		setenv_three.c	\
		unsetenv.c

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -I./include -g3
	rm *.o

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.o

fclean:	clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all
