/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** check_env
*/

#include <stdlib.h>

#include "my.h"
#include "my_world.h"

int check_env(char **env)
{
    int boolean = 0;

    for (int i = 0; env[i] != 0; i++) {
        if (my_strcmp(env[i], "DISPLAY=:0") == 0)
            boolean = 1;
    }
    if (boolean == 0)
        return 84;
    return 0;
}
