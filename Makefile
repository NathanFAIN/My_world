##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

CC	=	gcc

SRC	=	main.c 				\
		create_3d_map.c		\
		my_color_map.c		\
		create.c			\
		get_imput.c			\
		draw.c				\
		destroy.c			\
		button.c			\
		custom.c			\
		custom2.c			\
		smooth.c			\
		resize_pen.c		\
		menu.c				\
		menu2.c				\
		text_box.c			\
		water.c				\
		water1.c			\
		water2.c			\
		map.c				\
		my_help.c			\

OBJ	=	$(SRC:.c=.o)

NAME =	my_world

FLAGS	=	-W					\
			-Wextra				\
			-Wall				\
			-lcsfml-graphics	\
			-lcsfml-audio		\
			-lcsfml-window		\
			-lcsfml-system		\
			-lm					\

RM = rm -rf

all:
		$(CC) $(SRC) $(FLAGS) -g3 -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all
