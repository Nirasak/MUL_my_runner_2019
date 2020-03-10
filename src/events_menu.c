/*
** EPITECH PROJECT, 2019
** events_menu.c
** File description:
** events menu
*/

#include "my.h"

void press_button(game_t *game, sfEvent event, int i)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (i == 0)
            game->status = GAME;
        if (i == 1)
            game->status = OPTIONS;
        if (i == 2)
            game->status = LDB;
        if (i == 3)
            sfRenderWindow_close(game->wdw);
        game->menu.r_butt[i].top = 0;
    } else if (
        event.type == sfEvtMouseButtonPressed
        || game->menu.r_butt[i].top == 180)
        game->menu.r_butt[i].top = 180;
    else
        game->menu.r_butt[i].top = 90;
    sfSprite_setTextureRect(game->menu.s_butt[i], game->menu.r_butt[i]);
}

void my_events_menu(game_t *game, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(game->wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->wdw);
    for (int i = 0; i < 4; i++) {
        if (event.type == sfEvtMouseButtonReleased) {
            sfMusic_stop(game->click);
            sfMusic_play(game->click);
        }
        if (p_mouse.x >= game->menu.p_butt[i].x
            && p_mouse.x <= game->menu.p_butt[i].x + game->menu.r_butt[i].width
            && p_mouse.y >= game->menu.p_butt[i].y
            && p_mouse.y <= game->menu.p_butt[i].y
            + game->menu.r_butt[i].height) {
            press_button(game, event, i);
        }
        else {
            game->menu.r_butt[i].top = 0;
            sfSprite_setTextureRect(game->menu.s_butt[i], game->menu.r_butt[i]);
        }
    }
}
