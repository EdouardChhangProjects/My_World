/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** sprite
*/

#include "hud.h"
#include <fcntl.h>

hud_sprites_t *hud_sprite_set(char *path)
{
    int fd = open(path, O_RDONLY);
    hud_sprites_t *sprite = NULL;

    if (fd < 0)
        return NULL;
    close(fd);
    if ((sprite = malloc(sizeof(hud_sprites_t))) == NULL)
        return NULL;
    my_printf("PATH = %s\n", path);
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->size = sfTexture_getSize(sprite->texture);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    return sprite;
}
