/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** free_states
*/

#include "my_world.h"

int free_states(sfRenderStates *states)
{
    sfShader_destroy((sfShader *)states->shader);
    sfTexture_destroy((sfTexture *)states->texture);
    free(states);
    return 0;
}
