/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** global
*/

#include "my_world.h"

char *wd_spritefile[] = {
        "assets/BasicGreen.png",
        "assets/Swampset.png",
        "assets/IceSet.png",
        "assets/FireSet.png"
};

int **map = (int *[]){
        (int []){01, 01, 01, 01, 01, 01},
        (int []){01, 01, 01, 01, 01, 01},
        (int []){01, 01, 01, 01, 02, 01},
        (int []){01, 01, 01, 02, 03, 01},
        (int []){01, 01, 01, 01, 02, 01},
        (int []){01, 01, 01, 01, 01, 01},
};

int **map_text = (int *[]){
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
