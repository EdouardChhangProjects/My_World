##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Llib \
-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
override CPPFLAGS += -Iinclude -lmy -llist -lprintf -lprinterr -lm

SRC	=	src/HUD/components/buttons/set/pos_size.c	\
		src/HUD/components/buttons/render/draw.c	\
		src/HUD/components/buttons/init/struct.c	\
		src/HUD/parser/core/array_constructor.c		\
		src/HUD/components/buttons/set/border.c		\
		src/get_selected/get_selected_circle.c		\
		src/HUD/parser/utils/str_dup_from_to.c		\
		src/framebuffer/framebuffer_utils.c		\
		src/init_elements/init_text_state.c		\
		src/HUD/engine/utils/create_rect.c		\
		src/HUD/parser/utils/skip_balise.c		\
		src/HUD/parser/utils/file_to_str.c		\
		src/utils/circleshape_contains.c		\
		src/HUD/engine/utils/draw_rect.c		\
		src/HUD/parser/core/contructor.c		\
		src/matrix/update_proj_matrix.c			\
		src/HUD/parser/core/extractor.c			\
		src/init_elements/init_circle.c			\
		src/init_elements/init_window.c			\
		src/init_elements/init_matrix.c			\
		src/handle_errors/print_help.c			\
		src/HUD/engine/create/button.c			\
		src/HUD/parser/core/get_keys.c			\
		src/HUD/parser/button/action.c			\
		src/isometry/normalize_angle.c			\
		src/handle_errors/check_env.c			\
		src/utils/triangle_contains.c			\
		src/HUD/engine/events/event.c			\
		src/HUD/engine/init/actions.c			\
		src/HUD/engine/init/texture.c			\
		src/HUD/parser/button/parse.c			\
		src/init_elements/init_game.c			\
		src/isometry/draw_spritemap.c			\
		src/matrix/calc_end_matrix.c			\
		src/matrix/multiply_matrix.c			\
		src/HUD/engine/events/clic.c			\
		src/HUD/engine/render/draw.c			\
		src/isometry/pos_3d_to_2d.c			\
		src/matrix/rotate_matrix.c			\
		src/HUD/engine/init/init.c			\
		src/isometry/draw_points.c			\
		src/matrix/apply_matrix.c			\
		src/isometry/render_map.c			\
		src/isometry/update_dir.c			\
		src/matrix/show_matrix.c			\
		src/matrix/free_matrix.c			\
		src/isometry/draw_line.c			\
		src/utils/free_states.c				\
		src/my_world/my_world.c				\
		src/tools/level_tool.c				\
		src/utils/my_calloc.c				\
		src/utils/my_usleep.c				\
		src/isometry/points.c				\
		src/global.c					\
		src/events.c

OBJ = $(SRC:.c=.o)

TESTSRC = tests/test_make.c

TESTOBJ = $(TESTSRC:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

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

.PHONY: all clean fclean re tests_run cover debug
