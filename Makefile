##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Llib \
-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
override CPPFLAGS += -Iinclude -lmy -llist -lprintf -lprinterr -lm

SRC	=	src/hud/components/buttons/set/pos_size.c	\
		src/hud/components/buttons/init/struct.c	\
		src/hud/components/buttons/render/draw.c	\
		src/hud/components/buttons/set/border.c		\
		src/hud/parser/core/array_constructor.c		\
		src/get_selected/get_selected_circle.c		\
		src/hud/parser/utils/str_dup_from_to.c		\
		src/framebuffer/framebuffer_utils.c		\
		src/init_elements/init_text_state.c		\
		src/hud/engine/utils/create_rect.c		\
		src/hud/parser/utils/file_to_str.c		\
		src/hud/parser/utils/skip_balise.c		\
		src/utils/circleshape_contains.c		\
		src/hud/engine/utils/draw_rect.c		\
		src/hud/parser/core/contructor.c		\
		src/init_elements/init_window.c			\
		src/init_elements/init_matrix.c			\
		src/init_elements/init_circle.c			\
		src/matrix/update_proj_matrix.c			\
		src/hud/parser/core/extractor.c			\
		src/handle_errors/print_help.c			\
		src/isometry/normalize_angle.c			\
		src/hud/engine/create/button.c			\
		src/hud/parser/button/action.c			\
		src/hud/parser/core/get_keys.c			\
		src/handle_errors/check_env.c			\
		src/init_elements/init_game.c			\
		src/isometry/draw_spritemap.c			\
		src/utils/triangle_contains.c			\
		src/hud/engine/events/event.c			\
		src/hud/engine/init/actions.c			\
		src/hud/engine/init/texture.c			\
		src/hud/parser/button/parse.c			\
		src/matrix/calc_end_matrix.c			\
		src/matrix/multiply_matrix.c			\
		src/hud/engine/events/clic.c			\
		src/hud/engine/render/draw.c			\
		src/isometry/pos_3d_to_2d.c			\
		src/my_world/actions/menu.c			\
		src/isometry/draw_points.c			\
		src/my_world/change_view.c			\
		src/matrix/rotate_matrix.c			\
		src/hud/engine/init/init.c			\
		src/isometry/update_dir.c			\
		src/isometry/render_map.c			\
		src/utils/free_char_arr.c			\
		src/matrix/apply_matrix.c			\
		src/isometry/draw_line.c			\
		src/matrix/free_matrix.c			\
		src/matrix/show_matrix.c			\
		src/my_world/my_world.c				\
		src/utils/free_states.c				\
		src/tools/level_tool.c				\
		src/isometry/points.c				\
		src/my_world/events.c				\
		src/utils/my_calloc.c				\
		src/utils/my_usleep.c				\
		src/my_world/maps.c				\
		src/my_world/hud.c				\
		src/global.c

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
