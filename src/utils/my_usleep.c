/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_usleep
*/

#include "my_world.h"

int my_usleep(long long time)
{
    sfClock *clock = sfClock_create();

    while (sfClock_getElapsedTime(clock).microseconds < time);
    sfClock_destroy(clock);
    return 1;
}
