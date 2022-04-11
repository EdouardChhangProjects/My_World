/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_window
*/

#include "my_world.h"

sfRenderWindow *render_window(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *win = NULL;

    win = sfRenderWindow_create(mode, "my_world", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, FPS);
    if (win == NULL) {
        my_printerr("./my_world: Failed to create window\n");;
        return NULL;
    }
    return win;
}
