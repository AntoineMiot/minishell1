##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## infinAdd
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strcat.c	\
		my_strcpy.c	\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all