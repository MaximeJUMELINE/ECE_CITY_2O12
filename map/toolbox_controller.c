/**
    ECE_CITY 2012
    toolbox_controller.c
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"


/**************************
DRAG AND DROP DE LA TOOLBOX
**************************/
void jg_drag_toolbox(_generale *g) {

    if (mouse_x >= g->t->origin_x && mouse_x <= g->t->origin_x + g->t->toolbox->w && mouse_y >= g->t->origin_y && mouse_y <= g->t->origin_y + 22) {
        if (mouse_b&1)
            g->t->isCatch = 1;

    }

    if (g->t->isCatch) {
        g->t->origin_x = mouse_x - ( g->t->toolbox->w/2);
        if (mouse_y - 11 >= 20)
            g->t->origin_y = mouse_y - 11;
        else
            g->t->origin_y = 20;
        jg_reload_all(g);
    }

    if (!mouse_b&1)
        g->t->isCatch = 0;
}


/**************************************
CONTRÔLEUR DES ÉVÉNEMENTS DE LA TOOLBOX
**************************************/
void jg_toolbox_controller(_generale *g) {
    if (g->t->onDeactivate == 1) {
        g->t->onDeactivate = 0;
        jg_draw_toolbox(g);
        jg_reload_all(g);
    }
}


/****************************************************
DESSIN DE LA TOOLBOX ET DE SENS COMPOSANTES SI BESOIN
****************************************************/
void jg_draw_toolbox(_generale *g) {
    /*
        Fancy stuff here : buttons, ...
    */

    // On affiche la toolbox originale sur le buffer de la toolbox
    draw_sprite(g->t->buffer, g->t->toolbox, 0, 0);

    jg_display_toolbox(g, g->t->origin_x, g->t->origin_y);
}

/****************************************************
COLLE LE BUFFER DE LA TOOLBOX SUR LE BUFFER DE DESSIN
****************************************************/
void jg_display_toolbox(_generale *g, int catch_x, int catch_y) {
   draw_sprite(g->buffer, g->t->buffer, catch_x, catch_y);
}
