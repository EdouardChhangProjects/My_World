/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** apply_matrix
*/

#include "my_world.h"

sfVector3f apply_matrix(sfVector3f vector, float **matrix)
{
    sfVector3f dest = {0};

    dest.x = matrix[0][0] * vector.x + matrix[1][0] * vector.y +
                matrix[2][0] * vector.z + matrix[3][0];
    dest.y = matrix[0][1] * vector.x + matrix[1][1] * vector.y +
                matrix[2][1] * vector.z + matrix[3][1];
    dest.z = matrix[0][2] * vector.x + matrix[1][2] * vector.y +
                matrix[2][2] * vector.z + matrix[3][2];
    return dest;
}
