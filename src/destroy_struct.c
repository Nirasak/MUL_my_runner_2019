/*
** EPITECH PROJECT, 2020
** destroy_all.c
** File description:
** destroy all
*/

#include <stdlib.h>
#include "my.h"

void destroy_struct3(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(game->prlx.t_prlx[i]);
        sfSprite_destroy(game->prlx.s_prlx[i]);
    }
    free(game->prlx.t_prlx);
    free(game->prlx.s_prlx);
    free(game->prlx.p_prlx);
    free(game->prlx.r_prlx);
    free(game->fire.p_fire);
    free(game->menu.s_butt);
    free(game->menu.r_butt);
    free(game->menu.p_butt);
    for (int i = 0; game->ldb.value_ldb[i] != NULL; i++)
        free(game->ldb.value_ldb[i]);
    free(game->ldb.value_ldb);
    free(game->ldb.txt_ldb);
}

void destroy_struct2(game_t *game)
{
    sfFont_destroy(game->scr.font);
    sfClock_destroy(game->scr.c_scr);
    sfTexture_destroy(game->opt.t_opt);
    sfTexture_destroy(game->opt.t_vol);
    sfSprite_destroy(game->opt.s_opt);
    sfSprite_destroy(game->opt.s_vol);
    sfSprite_destroy(game->opt.s_change_vol);
    sfSprite_destroy(game->opt.s_return);
    sfTexture_destroy(game->fire.t_fire);
    sfSprite_destroy(game->fire.s_fire);
    sfClock_destroy(game->fire.c_fire);
    sfTexture_destroy(game->ness.t_ness);
    sfTexture_destroy(game->ness.t_win);
    sfTexture_destroy(game->ness.t_lose);
    sfSprite_destroy(game->ness.s_ness);
    sfSprite_destroy(game->ness.s_win);
    sfSprite_destroy(game->ness.s_lose);
    sfClock_destroy(game->ness.c_ness);
    destroy_struct3(game);
}

void destroy_struct(game_t *game)
{
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->click);
    sfTexture_destroy(game->menu.t_menu);
    sfTexture_destroy(game->menu.t_butt);
    sfSprite_destroy(game->menu.s_menu);
    for (int i = 0; i < 4; i++)
        sfSprite_destroy(game->menu.s_butt[i]);
    sfTexture_destroy(game->ldb.t_ldb);
    sfSprite_destroy(game->ldb.s_ldb);
    sfFont_destroy(game->ldb.font_ldb);
    for (int i = 0; i < 20; i++)
        sfText_destroy(game->ldb.txt_ldb[i]);
    destroy_struct2(game);
}
