/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define ABS(value) (((value) > 0) ? (value) : (-value))

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdbool.h>

#define MENU 0
#define GAME 1
#define OPTIONS 2
#define END 3
#define LDB 4

typedef struct ldb
{
    sfTexture *t_ldb;
    sfSprite *s_ldb;
    sfIntRect r_ldb;
    sfVector2f p_ldb;
    char **value_ldb;
    sfFont *font_ldb;
    sfText **txt_ldb;
    sfVector2f p_value_ldb;
} ldb_t;

typedef struct scr
{
    sfFont *font;
    sfText *txt_score;
    sfVector2f p_score;
    int score;
    sfClock *c_scr;
    sfTime time_scr;
    float sec_scr;
} scr_t;

typedef struct opt
{
    sfTexture *t_opt;
    sfTexture *t_vol;
    sfSprite *s_opt;
    sfSprite *s_vol;
    sfSprite *s_change_vol;
    sfSprite *s_return;
    sfIntRect r_opt;
    sfIntRect r_vol;
    sfIntRect r_change_vol;
    sfIntRect r_return;
    sfVector2f p_opt;
    sfVector2f p_vol;
    sfVector2f p_change_vol;
    sfVector2f p_return;
    int status_vol;
} opt_t;

typedef struct menu
{
    sfTexture *t_menu;
    sfTexture *t_butt;
    sfSprite *s_menu;
    sfSprite **s_butt;
    sfIntRect r_menu;
    sfIntRect *r_butt;
    sfVector2f p_menu;
    sfVector2f *p_butt;
} menu_t;

typedef struct fire
{
    sfTexture *t_fire;
    sfSprite *s_fire;
    sfVector2f *p_fire;
    sfIntRect r_fire;
    sfClock *c_fire;
    sfTime time_fire;
    float sec_fire;
    int nb_fire;
} fire_t;

typedef struct ness
{
    sfTexture *t_ness;
    sfSprite *s_ness;
    sfVector2f p_ness;
    sfIntRect r_ness;
    sfClock *c_ness;
    sfTime time_ness;
    float sec_ness;
    bool jump;
    bool status_jump;
    sfTexture *t_win;
    sfSprite *s_win;
    sfTexture *t_lose;
    sfSprite *s_lose;
    sfVector2f p_win;
    sfIntRect r_win;
} ness_t;

typedef struct prlx
{
    sfTexture **t_prlx;
    sfSprite **s_prlx;
    sfVector2f *p_prlx;
    sfIntRect *r_prlx;
    sfClock *c_prlx;
    sfTime time_prlx;
    float sec_prlx;
} prlx_t;

typedef struct game
{
    sfRenderWindow *wdw;
    sfMusic *music;
    sfMusic *click;
    ness_t ness;
    fire_t fire;
    prlx_t prlx;
    menu_t menu;
    opt_t opt;
    scr_t scr;
    ldb_t ldb;
    int status;
    int win;
    char *pseudo;
} game_t;

int my_runner(game_t *game, char *str);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(char const *str);
void create_window(game_t *game);
void create_player(ness_t *ness);
bool create_parallax(prlx_t *prlx);
bool create_fire(fire_t *fire, char *str);
bool create_menu(menu_t *menu);
void create_opt(opt_t *opt);
bool create_ldb(ldb_t *ldb);
void create_music(game_t *game);
void create_score(scr_t *scr);
bool create_fire_infinite(fire_t *fire);
void loop_game(game_t *game, char *str);
void loop_menu(game_t *game);
void loop_opt(game_t *game);
void clock_ness(game_t *game);
void clock_prlx(game_t *game);
void clock_fire(game_t *game);
void clock_score(game_t *game);
void my_events_menu(game_t *game, sfEvent event);
void my_events_opt(game_t *game, sfEvent event);
char *my_itoa(int nb);
int my_atoi(char *str);
void check_score(game_t *game);
char *get_score(char *str);
void get_name(char *str, sfText *txt);
int my_strlen(char const *str);
char *my_strdup(char const *str);
char **get_from_file(char *file);
char *my_strcpy(char const *src, char *dest);
void put_in_file(char *file, char **tab);
void loop_ldb(game_t *game);
void my_events_opt3(game_t *game, sfEvent event, sfVector2i p_mouse);
void destroy_struct(game_t *game);
bool init_struct(game_t *game, char *str);

#endif
