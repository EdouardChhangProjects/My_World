/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_text_state
*/

#include "my_world.h"

sfRenderStates *init_text_state(wd_spritetype_e type)
{
    sfRenderStates *states = my_memset(sizeof(sfRenderStates), NULL);
    sfTexture *texture = sfTexture_createFromFile(wd_spritefile[type],
                                                  NULL);

    if (texture == NULL || states == NULL) {
        return NULL;
    }
    states->shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_Identity;
    states->texture = texture;
    return states;
}
