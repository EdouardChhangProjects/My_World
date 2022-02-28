/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "my_world.h"


void analyse_events(sfRenderWindow *win, sfEvent event, double *x, double *y)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        *x -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        *x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        *y += 1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        *y -= 1;
}


int gameloop(void)
{
    sfEvent event;
    sfRenderWindow *win = render_window();
    framebuffer_t *framebuffer = framebuffer_create(WIDTH, HEIGHT);
    double *angle_x = my_memset(sizeof(double), NULL);
    double *angle_y = my_memset(sizeof(double), NULL);

    *angle_x = 35;
    *angle_y = 45;
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event)) {
            analyse_events(win, event, angle_x, angle_y);
        }
        render_map(win, framebuffer, *angle_x, *angle_y);
    }
    sfRenderWindow_destroy(win);
    return 0;
}
