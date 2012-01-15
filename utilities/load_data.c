/**
    ECE_CITY 2012
    load_data.c
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"

void jg_load_menu(_generale *g) {
    g->m->menu = jg_load_bitmap("img/menu/menu.bmp");
    g->m->menu0 = jg_load_bitmap("img/menu/menu0.bmp");
    g->m->menu1 = jg_load_bitmap("img/menu/menu1.bmp");
    g->m->menu2 = jg_load_bitmap("img/menu/menu2.bmp");
    g->m->menu3 = jg_load_bitmap("img/menu/menu3.bmp");
    g->m->menu1_0 = jg_load_bitmap("img/menu/menu1-0.bmp");
    g->m->menu1_1 = jg_load_bitmap("img/menu/menu1-1.bmp");
    g->m->menu1_2 = jg_load_bitmap("img/menu/menu1-2.bmp");
    g->m->menu1_3 = jg_load_bitmap("img/menu/menu1-3.bmp");
    g->m->menu1_4 = jg_load_bitmap("img/menu/menu1-4.bmp");
    g->m->menu2_0 = jg_load_bitmap("img/menu/menu2-0.bmp");
    g->m->menu2_1 = jg_load_bitmap("img/menu/menu2-1.bmp");
    g->m->menu2_2 = jg_load_bitmap("img/menu/menu2-2.bmp");
    g->m->menu2_3 = jg_load_bitmap("img/menu/menu2-3.bmp");
    g->m->menu3_0 = jg_load_bitmap("img/menu/menu3-0.bmp");
    g->m->menu3_1 = jg_load_bitmap("img/menu/menu3-1.bmp");
    g->m->check_on = jg_load_bitmap("img/menu/check_on.bmp");
    g->m->check_off = jg_load_bitmap("img/menu/check_off.bmp");
}

void jg_load_toolbox(_generale *g) {
    g->t->toolbox = jg_load_bitmap("img/toolbox/toolbox.bmp");
    g->t->scroll_up = jg_load_bitmap("img/toolbox/scroll_up.bmp");
    g->t->scroll_down = jg_load_bitmap("img/toolbox/scroll_down.bmp");
    g->t->scroll_right = jg_load_bitmap("img/toolbox/scroll_right.bmp");
    g->t->scroll_left = jg_load_bitmap("img/toolbox/scroll_left.bmp");
}

void jg_load_tiles(_generale *g) {
    g->tiles->water = jg_load_bitmap("img/tiles/water.bmp");
    g->tiles->ground = jg_load_bitmap("img/tiles/ground.bmp");
}
