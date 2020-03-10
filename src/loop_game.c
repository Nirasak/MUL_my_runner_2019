/*
** EPITECH PROJECT, 2019
** loop_game.c
** File description:
** loop game
*/

#include <stdlib.h>
#include "my.h"

void my_events_game(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->wdw);
    if (game->win == 0 && event.type == sfEvtKeyPressed
        && event.key.code == sfKeySpace
        && game->ness.jump == false)
        game->ness.jump = true;
    if (game->win != 0 && (event.type == sfEvtKeyReleased
        || event.type == sfEvtMouseButtonReleased))
        game->status = MENU;
}

void display_game(game_t *game)
{
    char *tmp_score = my_itoa(game->scr.score);

    sfText_setString(game->scr.txt_score, tmp_score);
    free(tmp_score);
    sfRenderWindow_clear(game->wdw, sfBlack);
    for (int i = 3; i >= 0; i--)
        sfRenderWindow_drawSprite(game->wdw, game->prlx.s_prlx[i], NULL);
    sfRenderWindow_drawSprite(game->wdw, game->ness.s_ness, NULL);
    for (int i = 0; i < game->fire.nb_fire; i++) {
        sfSprite_setPosition(game->fire.s_fire, game->fire.p_fire[i]);
        sfRenderWindow_drawSprite(game->wdw, game->fire.s_fire, NULL);
    }
    if (game->win == -1)
        sfRenderWindow_drawSprite(game->wdw, game->ness.s_lose, NULL);
    if (game->win == 1)
        sfRenderWindow_drawSprite(game->wdw, game->ness.s_win, NULL);
    sfRenderWindow_drawText(game->wdw, game->scr.txt_score, NULL);
}

void check_colision(game_t *game)
{
    for (int i = 0; i < game->fire.nb_fire; i++)
        if (((game->ness.p_ness.x + 8 >= game->fire.p_fire[i].x
        && game->ness.p_ness.x + game->ness.r_ness.width - 9 <=
        game->fire.p_fire[i].x + game->fire.r_fire.width)
        || (game->ness.p_ness.x + game->ness.r_ness.width - 9 >=
        game->fire.p_fire[i].x && game->ness.p_ness.x + game->ness.r_ness.width
        <= game->fire.p_fire[i].x + game->fire.r_fire.width))
        && (game->ness.p_ness.y + game->ness.r_ness.height - 12 >=
        game->fire.p_fire[i].y && game->ness.p_ness.y +
        game->ness.r_ness.height - 12 <= game->fire.p_fire[i].y
        + game->fire.r_fire.height)) {
            game->win = -1;
            game->ness.r_ness.left = 7;
            game->ness.r_ness.top = 455;
            sfSprite_setTextureRect(game->ness.s_ness, game->ness.r_ness);
        }
    if (game->ness.p_ness.x > game->fire.p_fire[game->fire.nb_fire - 1].x + 500)
        game->win = 1;
}

void loop_game(game_t *game, char *str)
{
    sfEvent event;

    while (game->status == GAME && sfRenderWindow_isOpen(game->wdw)) {
        while (sfRenderWindow_pollEvent(game->wdw, &event))
            my_events_game(game, event);
        check_colision(game);
        if (game->win != -1)
            clock_ness(game);
        clock_score(game);
        clock_prlx(game);
        clock_fire(game);
        display_game(game);
        sfRenderWindow_display(game->wdw);
    }
    check_score(game);
    destroy_struct(game);
    init_struct(game, str);
}
