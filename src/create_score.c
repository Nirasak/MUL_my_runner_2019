/*
** EPITECH PROJECT, 2020
** create_score.c
** File description:
** create score
*/

#include "my.h"

void clock_score(game_t *game)
{
    if (game->win != 0)
        return;
    game->scr.time_scr = sfClock_getElapsedTime(game->scr.c_scr);
    game->scr.sec_scr = game->scr.time_scr.microseconds / 1000000.0f;
    if (game->scr.sec_scr >= 1) {
        game->scr.score++;
        sfClock_restart(game->scr.c_scr);
    }
}

void create_score(scr_t *scr)
{
    scr->font = sfFont_createFromFile("font/sans_serif.ttf");
    scr->txt_score = sfText_create();
    sfText_setFont(scr->txt_score, scr->font);
    sfText_setColor(scr->txt_score, sfWhite);
    sfText_setCharacterSize(scr->txt_score, 62);
    scr->p_score.x = 1600;
    scr->p_score.y = 50;
    sfText_setPosition(scr->txt_score, scr->p_score);
    scr->c_scr = sfClock_create();
    scr->sec_scr = 0;
    scr->score = 0;
}
