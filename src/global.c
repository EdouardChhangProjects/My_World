/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** global
*/

#include "my_world.h"

int **map = (int *[]) {
        (int []){0, 0, 0, 0, 0, 0},
        (int []){0, 0, 0, 0, 0, 0},
        (int []){0, 0, 0, 0, 2, 0},
        (int []){0, 0, 0, 2, 0, 0},
        (int []){0, 1, 1, 0, 2, 0},
        (int []){0, 0, 0, 0, 0, 0},
};

int **map_text = (int *[]) {
        (int []){04, 01, 01, 02, 01},
        (int []){01, 01, 02, 01, 01},
        (int []){01, 02, 04, 01, 04},
        (int []){02, 01, 01, 03, 03},
        (int []){01, 01, 04, 03, 03},
};

sfVector2f wd_texCoords[] = {
        (sfVector2f) {.x = 0, .y = 0},
        (sfVector2f) {.x = 16, .y = 0},
        (sfVector2f) {.x = 16, .y = 16},
        (sfVector2f) {.x = 0, .y = 16}
};
