/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_matrix
*/

#include "my_world.h"

float **init_matrix(int empty)
{
    float **dest = my_memset(sizeof(float *) * 4, NULL);

    for (int i = 0; i < 4; ++i)
        dest[i] = my_memset(sizeof(float) * 4, NULL);
    for (int x = 0; x < 16; ++x) {
        if ((x / 4) == (x % 4) && empty != 1)
            dest[x / 4][x % 4] = 1;
        else
            dest[x / 4][x % 4] = 0;
    }
    return dest;
}

float **init_proj_matrix()
{
    float **dest = init_matrix(1);

    dest[0][0] = SCREEN_RATIO * FOVRAD;
    dest[1][1] = FOVRAD;
    dest[2][2] = FFAR * (FFAR - FNEAR);
    dest[3][2] = (-FFAR * FNEAR) / (FFAR - FNEAR);
    dest[2][3] = 1;
    dest[3][3] = 0;
    return dest;
}
