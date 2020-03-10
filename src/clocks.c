/*
** EPITECH PROJECT, 2020
** clocks.c
** File description:
** clocks
*/

#include "my.h"

void clock_fire(game_t *game)
{
    game->fire.time_fire = sfClock_getElapsedTime(game->fire.c_fire);
    game->fire.sec_fire = game->fire.time_fire.microseconds / 1000000.0f;
    if (game->fire.sec_fire >= 0.095) {
        game->fire.r_fire.left += 122;
        if (game->fire.r_fire.left > 366)
            game->fire.r_fire.left = 0;
        sfSprite_setTextureRect(game->fire.s_fire, game->fire.r_fire);
        sfClock_restart(game->fire.c_fire);
    }
}

void ness_jump_move(game_t *game)
{
    if (game->ness.jump == true && game->ness.status_jump == true) {
        game->ness.p_ness.y -= 6;
        if (game->ness.p_ness.y < 640)
            game->ness.status_jump = false;
    }
    if (game->ness.jump == true && game->ness.status_jump == false) {
        game->ness.p_ness.y += 6;
        if (game->ness.p_ness.y == 840) {
            game->ness.jump = false;
            game->ness.status_jump = true;
        }
    }
    sfSprite_setPosition(game->ness.s_ness, game->ness.p_ness);
}

void ness_jump(game_t *game)
{
    game->ness.r_ness.top = 307;
    game->ness.r_ness.left += 150;
    if (game->ness.r_ness.left > 607)
        game->ness.r_ness.left = 7;
    sfSprite_setTextureRect(game->ness.s_ness, game->ness.r_ness);
    sfClock_restart(game->ness.c_ness);
}

void clock_ness(game_t *game)
{
    game->ness.time_ness = sfClock_getElapsedTime(game->ness.c_ness);
    game->ness.sec_ness = game->ness.time_ness.microseconds / 1000000.0f;
    if (game->ness.sec_ness >= 0.095) {
        if (game->ness.jump == true) {
            ness_jump(game);
            return;
        }
        game->ness.r_ness.top = 157;
        game->ness.r_ness.left += 150;
        if (game->ness.r_ness.left > 1057)
            game->ness.r_ness.left = 7;
        sfSprite_setTextureRect(game->ness.s_ness, game->ness.r_ness);
        sfClock_restart(game->ness.c_ness);
    }
}

void clock_prlx(game_t *game)
{
    game->prlx.time_prlx = sfClock_getElapsedTime(game->prlx.c_prlx);
    game->prlx.sec_prlx = game->prlx.time_prlx.microseconds / 1000000.0f;
    if (game->prlx.sec_prlx > 0.01) {
        ness_jump_move(game);
        if (game->win != -1) {
            game->prlx.r_prlx[0].left += 6;
            for (int i = 0; i < game->fire.nb_fire; i++)
                game->fire.p_fire[i].x -= 6;
            game->prlx.r_prlx[1].left += 3;
            game->prlx.r_prlx[2].left += 2;
            sfClock_restart(game->prlx.c_prlx);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (game->prlx.r_prlx[i].left >= 1920)
            game->prlx.r_prlx[i].left -= 1920;
        sfSprite_setTextureRect(game->prlx.s_prlx[i], game->prlx.r_prlx[i]);
    }
}
