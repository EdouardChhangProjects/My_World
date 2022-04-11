/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** show_matrix
*/

#include "my_world.h"

int show_matrix(float **matrix)
{
    my_printf("MATRIX:\n");
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            my_printf(" [%f] ", matrix[x][y]);
        }
        my_printf("\n");
    }
    my_printf("END OF MATRIX\n");
    return 0;
}
