/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** framebuffer_utils
*/

#include "my_world.h"

framebuffer_t *clean_framebuffer(framebuffer_t *fb)
{
    unsigned int index = 0;

    for (unsigned int x = 0; x < fb->width; ++x) {
        for (unsigned int y = 0; y < fb->height; ++y) {
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
