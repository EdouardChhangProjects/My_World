/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** sprite
*/

#include "hud.h"
#include <fcntl.h>

sfTexture *hud_texture_set(char *path)
{
    int fd = open(path, O_RDONLY);
    sfTexture *texture;

    if (fd < 0) {
        my_printerr("\t\t>>> texture not found: %s\n", path);
        return NULL;
    }
    close(fd);
    texture = sfTexture_createFromFile(path, NULL);
    if (texture == NULL)
        my_printerr("\t\t>>> fail to load texture: %s\n", path);
    return texture;
}
