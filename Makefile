
##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/my_runner.c	\
		src/my_strcmp.c	\
		src/my_putstr.c	\
		src/create_window.c	\
		src/create_player.c	\
		src/create_parallax.c	\
		src/loop_game.c	\
		src/create_fire.c	\
		src/clocks.c	\
		src/create_menu.c	\
		src/loop_menu.c	\
		src/events_menu.c	\
		src/create_opt.c	\
		src/loop_opt.c	\
		src/events_opt.c	\
		src/create_music.c	\
		src/get_next_line.c	\
		src/create_score.c	\
		src/my_itoa.c	\
		src/my_atoi.c	\
		src/create_ldb.c	\
		src/check_score.c	\
		src/get_from_file.c	\
		src/put_in_file.c	\
		src/loop_leaderboard.c	\
		src/destroy_struct.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	 -I include/

CSFML	=	-lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CSFML) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
