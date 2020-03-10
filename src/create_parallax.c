/*
** EPITECH PROJECT, 2019
** create_parallax.c
** File description:
** create parallax
*/

#include <stdlib.h>
#include "my.h"

void init_parallax(prlx_t *prlx)
{
    for (int i = 0; i < 4; i++) {
        prlx->s_prlx[i] = sfSprite_create();
        sfSprite_setTexture(prlx->s_prlx[i], prlx->t_prlx[i], sfTrue);
        prlx->r_prlx[i].left = 0;
        prlx->r_prlx[i].top = 50;
        prlx->r_prlx[i].width = 1920;
        prlx->r_prlx[i].height = 1030;
        sfSprite_setTextureRect(prlx->s_prlx[i], prlx->r_prlx[i]);
        prlx->p_prlx[i].x = 0;
        prlx->p_prlx[i].y = 0;
        sfSprite_setPosition(prlx->s_prlx[i], prlx->p_prlx[i]);
    }
    prlx->c_prlx = sfClock_create();
    prlx->sec_prlx = 0;
}

bool create_parallax(prlx_t *prlx)
{
    prlx->t_prlx = malloc(sizeof(sfTexture *) * 4);
    prlx->s_prlx = malloc(sizeof(sfSprite *) * 4);
    prlx->r_prlx = malloc(sizeof(sfIntRect) * 4);
    prlx->p_prlx = malloc(sizeof(sfVector2f) * 4);
    if (prlx->t_prlx == NULL || prlx->s_prlx == NULL
        || prlx->r_prlx == NULL || prlx->p_prlx == NULL)
        return (false);
    prlx->t_prlx[0] = sfTexture_createFromFile("assets/prlx1.png", NULL);
    prlx->t_prlx[1] = sfTexture_createFromFile("assets/prlx2.png", NULL);
    prlx->t_prlx[2] = sfTexture_createFromFile("assets/prlx3.png", NULL);
    prlx->t_prlx[3] = sfTexture_createFromFile("assets/sky.png", NULL);
    init_parallax(prlx);
    return (true);
}
