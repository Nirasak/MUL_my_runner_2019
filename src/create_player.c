/*
** EPITECH PROJECT, 2019
** create_player.c
** File description:
** create player
*/

#include "my.h"

void create_win_lose(ness_t *ness)
{
    ness->s_win = sfSprite_create();
    ness->s_lose = sfSprite_create();
    ness->t_win = sfTexture_createFromFile("assets/win.png", NULL);
    ness->t_lose = sfTexture_createFromFile("assets/lose.png", NULL);
    sfSprite_setTexture(ness->s_win, ness->t_win, sfTrue);
    sfSprite_setTexture(ness->s_lose, ness->t_lose, sfTrue);
    ness->r_win.left = 0;
    ness->r_win.top = 0;
    ness->r_win.width = 1920;
    ness->r_win.height = 1080;
    sfSprite_setTextureRect(ness->s_win, ness->r_win);
    sfSprite_setTextureRect(ness->s_lose, ness->r_win);
    ness->p_win.x = 0;
    ness->p_win.y = 0;
    sfSprite_setPosition(ness->s_win, ness->p_win);
    sfSprite_setPosition(ness->s_lose, ness->p_win);
}

void create_player(ness_t *ness)
{
    ness->s_ness = sfSprite_create();
    ness->t_ness = sfTexture_createFromFile("assets/ness.png", NULL);
    sfSprite_setTexture(ness->s_ness, ness->t_ness, sfTrue);
    ness->r_ness.left = 7;
    ness->r_ness.top = 157;
    ness->r_ness.width = 143;
    ness->r_ness.height = 143;
    sfSprite_setTextureRect(ness->s_ness, ness->r_ness);
    ness->p_ness.x = 100;
    ness->p_ness.y = 840;
    sfSprite_setPosition(ness->s_ness, ness->p_ness);
    ness->c_ness = sfClock_create();
    ness->sec_ness = 0;
    ness->jump = false;
    ness->status_jump = true;
    create_win_lose(ness);
}
