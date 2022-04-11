/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** multiply_matrix
*/

#include "my_world.h"

float calculate_point(float **matrix1, float **matrix2, int x, int y)
{
    float sum = 0;

    for (int i = 0; i < 4; ++i) {
        sum += matrix1[x][i] * matrix2[i][y];
    }
    return sum;
}

float **multiply_matrix(float **matrix1, float **matrix2)
{
    float **dest = init_matrix(0);
    int x = 0;
    int y = 0;

    for (int i = 0; i < 16; ++i) {
        x = i / 4;
        y = i % 4;
        dest[x][y] = calculate_point(matrix1, matrix2, x, y);
    }
    return dest;
}
