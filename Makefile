##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Llib \
-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
override CPPFLAGS += -Iinclude -lmy -llist -lprintf -lprinterr -lm

TESTSRC = tests/test_make.c

TESTOBJ = $(TESTSRC:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

SRC =	src/handle_errors/check_env.c		\
		src/handle_errors/print_help.c		\
		src/my_world/my_world.c				\
		src/init_elements/init_window.c		\
		src/init_elements/init_game.c		\
		src/init_elements/init_text_state.c		\
		src/isometry/render_map.c			\
		src/isometry/points.c				\
		src/isometry/draw_line.c			\
		src/isometry/draw_spritemap.c 		\
		src/utils/my_calloc.c 				\
		src/framebuffer/framebuffer_utils.c	\

OBJ = $(SRC:.c=.o)

NAME = my_world

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
				make -C lib/my
				make -C lib/printf
				make -C lib/printerr
				make -C lib/list
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
				rm -f $(OBJ) $(MAINOBJ)
				find . -type f -name '*.gcda' -delete
				find . -type f -name '*.gcno' -delete
				make clean -C lib/my
				make clean -C lib/printf
				make clean -C lib/printerr
				make clean -C lib/list

fclean: clean
				rm -f $(NAME)
				make fclean -C lib/my
				make fclean -C lib/printf
				make fclean -C lib/printerr
				make fclean -C lib/list

re: fclean all

tests_run:	CFLAGS += -lcriterion --coverage
tests_run: re $(TESTOBJ)
				gcc -o unit_tests $(TESTOBJ) $(SRC) $(CFLAGS) $(CPPFLAGS)
				./unit_tests

cover:
				gcovr --exclude tests
				gcovr --exclude tests --branches
				rm -f unit_tests*

debug: CFLAGS += -g
debug: re
