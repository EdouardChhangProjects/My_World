/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** print_map
*/

#include "my_world.h"

double to_radiant(double angle)
{
    return (double)(angle * M_PI / 180);
}

framebuffer_t *clean_framebuffer(framebuffer_t *fb)
{
    unsigned int index = 0;

    for (int x = 0; x < fb->width; ++x) {
        for (int y = 0; y < fb->height; ++y) {
            index = (4 * fb->width * y) + (4 * x);
            fb->pixels[index] = sfBlack.r;
            fb->pixels[index + 1] = sfBlack.g;
            fb->pixels[index + 2] = sfBlack.b;
            fb->pixels[index + 3] = sfBlack.a;
        }
    }
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buffer = malloc(sizeof(framebuffer_t));
    sfUint8 *ptr = my_memset(sizeof(sfUint8) * (width * height * 4), NULL);

    buffer->width = width;
    buffer->height = height;
    buffer->pixels = ptr;
    buffer->texture = sfTexture_create(WIDTH, HEIGHT);
    buffer->sprite = sfSprite_create();
    sfSprite_setTexture(buffer->sprite, buffer->texture, sfTrue);
    return (buffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    unsigned int index = (4 * framebuffer->width * y) + (4 * x);

    framebuffer->pixels[index] = color.r;
    framebuffer->pixels[index + 1] = color.g;
    framebuffer->pixels[index + 2] = color.b;
    framebuffer->pixels[index + 3] = color.a;
}

framebuffer_t *print_point(int x, int y, int z, framebuffer_t *fb, double
angle_x, double angle_y)
{
    x = x * 64;
    y = y * 64;
    int point_x = cos(to_radiant(angle_x)) * x - cos(to_radiant
            (angle_x)) * y;
    int point_y = sin(to_radiant(angle_y)) * y + sin(to_radiant
            (angle_y)) * x - z;
    point_x += WIDTH / 2;
    point_y += HEIGHT / 4;
    if (point_x > 0 && point_x < fb->width && point_y > 0 && point_y <
    fb->height) {
        my_put_pixel(fb, point_x, point_y, sfWhite);
    }
}

int render_map(sfRenderWindow* win, framebuffer_t *fb, double
angle_x, double angle_y) {

    clean_framebuffer(fb);
    for (int y = 0; y <= 6; ++y) {
        for (int x = 0; x <= 6; ++x) {
            print_point(x, y, map[x][y], fb, angle_x, angle_y);
        }
    }
    sfTexture_updateFromPixels(fb->texture, fb->pixels, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(win, fb->sprite, NULL);
    sfRenderWindow_display(win);
    return 0;
}
