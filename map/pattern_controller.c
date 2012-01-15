/**
    ECE_CITY 2012
    patern_controller.c
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"


/******************************
SCROLLER LE TERRAIN À LA SOURIS
******************************/
void jg_scroll_controller(_generale *g) {
    /// Scroll vers la gauche
    if (mouse_b&1 && mouse_x >= g->t->origin_x + 76 && mouse_x <= g->t->origin_x + 97 && mouse_y >= g->t->origin_y + 275 && mouse_y <= g->t->origin_y + 296) {
        g->c->scroll_x += 1 + g->c->zoom/4;
        g->t->onDeactivate = 1;
        draw_sprite(g->t->buffer, g->t->scroll_left, 76, 275);
        jg_reload_all(g);
    }

    /// Scroll vers la droite
    if (mouse_b&1 && mouse_x >= g->t->origin_x + 27 && mouse_x <= g->t->origin_x + 49 && mouse_y >= g->t->origin_y + 275 && mouse_y <= g->t->origin_y + 296) {
        g->c->scroll_x -= 1 + g->c->zoom/4;
        g->t->onDeactivate = 1;
        draw_sprite(g->t->buffer, g->t->scroll_right, 27, 275);
        jg_reload_all(g);
    }

    /// Scroll vers le haut
    if (mouse_b&1 && mouse_x >= g->t->origin_x + 3 && mouse_x <= g->t->origin_x + 24 && mouse_y >= g->t->origin_y + 275 && mouse_y <= g->t->origin_y + 296 ) {
        g->c->scroll_y += 1 + g->c->zoom/4;
        g->t->onDeactivate = 1;
        draw_sprite(g->t->buffer, g->t->scroll_up, 3, 275);
        jg_reload_all(g);
    }

    /// Scroll vers le bas
    if (mouse_b&1 && mouse_x >= g->t->origin_x + 51 && mouse_x <= g->t->origin_x + 73 && mouse_y >= g->t->origin_y + 275 && mouse_y <= g->t->origin_y + 296) {
        g->c->scroll_y -= 1 + g->c->zoom/4;
        g->t->onDeactivate = 1;
        draw_sprite(g->t->buffer, g->t->scroll_down, 51, 275);
        jg_reload_all(g);
    }
}

/**************************
ZOOMER OU DÉZOOMER LA CARTE
**************************/
void jg_zoom_controller(_generale *g) {
    /// Zoom
    if (mouse_b&1 && mouse_x >= g->t->origin_x + 67 && mouse_x <= g->t->origin_x + 97 && mouse_y >= g->t->origin_y + 17 && mouse_y <= g->t->origin_y + 45) {
        if (g->c->zoom <= 40) g->c->zoom += 1;
        g->c->scroll_x = -400;
        g->c->scroll_y = -400;
        jg_reload_all(g);
    }

    /// Dézoom
    if (mouse_b&1 && mouse_x >= g->t->origin_x + 1 && mouse_x <= g->t->origin_x + 31 && mouse_y >= g->t->origin_y + 17 && mouse_y <= g->t->origin_y + 45) {
        if (g->c->zoom > 0) g->c->zoom -= 1;
        g->c->scroll_x = 0;
        g->c->scroll_y = 0;
        jg_reload_all(g);
    }
}

/********************************************************************************************
AFFICHER LE QUADRILLAGE DU TERRAIN EN FONCTION D'UN FACTEUR DE ZOOM ET D'UN FACTEUR DE SCROLL
********************************************************************************************/
void jg_draw_grid(_generale *g, int scroll_w, int scroll_h, int zoom) {
    // Initialisation des ressources locales
    int i = 0;
    int j = g->map->h/2 +50*zoom;

    // Dessin des lignes obliques de la gauche vers le bas
    for (i = OFFSET_X + scroll_w; i <= g->map->w/2 + scroll_w + 50*zoom; i += LOS_W/2 + zoom) {
        line(g->map, i + scroll_w, j + scroll_h, i + g->map->w/2+50*zoom - OFFSET_X + scroll_w, j - g->map->h/2-50*zoom + scroll_h, makecol(255, 255, 255));

        // Gestion d'un compteur interne (simulation de boucle for simulténée)
        j += LOS_H/2 + zoom;

    }

    // Nouvelle initialisation
    j = g->map->h/2 + 50*zoom;

    // Dessin des lignes obliques de la gauche vers le haut
    for (i = OFFSET_X + scroll_w; i <= g->map->w/2 + scroll_w + 50*zoom; i+= LOS_W/2 + zoom) {
        line(g->map, i + scroll_w, j + scroll_h, i + g->map->w/2+50*zoom - OFFSET_X + scroll_w, j + g->map->h/2+50*zoom + scroll_h, makecol(255, 255, 255));

        // Gestion d'un compteur interne (simulation de boucle for simulténée)
        j -= LOS_H/2 + zoom;

    }

    // Affichage à l'écran de la grille
    blit(g->map, g->buffer, 0, 0, 0, 0, g->map->w, g->map->h);
}


/***************
DESSINE LA TERRE
***************/
void jg_paint_ground(_generale *g) {
    int i = 0;      // Compteur
    int j = 0;      // Compteur
    int NB = 25;    // Nombre de losanges (par moitié)
    int x = 0;      // Abscisse de pose
    int y = 20;      // Ordonnée de pose
    printf("%i,%i\n", g->map->w, g->map->h);
    for (i = OFFSET_X - 16/2; i < g->map->w/2; i+= LOS_W/2 + g->c->zoom) {
        for (j = 20; j < g->map->h/2; j+= LOS_H/2 + g->c->zoom) {
            stretch_sprite(g->map, g->tiles->ground, i + g->c->scroll_x, j + g->c->scroll_y, 16, 10);
        }


    }
/*
    for (i = 0; i < NB; i++) {
        int k = 0;
        for (j = 0; j < NB - i - 1; j++) { /// NE RIEN DESSINER
            x += 16 ;
        }
        for (; j < 2*NB-1; j++) {
            if (k < 2*i + 1) {             /// DESSINER
                x += 16;
                stretch_sprite(g->map, g->tiles->ground, x - 16/2, y, 16, 10);
                stretch_sprite(g->map, g->tiles->ground, x - 16, y - 10/2, 16, 10);
            }
            k++;
        }
        /// PASSER À LA LIGNE SUIVANTE
        y += 10;
        x = 0;
    }
    */

    blit(g->map, g->buffer, 0, 0, 0, 0, g->map->w, g->map->h);
}


/************
DESSINE L'EAU
************/
void jg_paint_water(_generale *g) {
    int i = 0;
    int j = 0;

    for (i = 0; i <= g->map->w; i+= g->tiles->water->w + g->c->zoom) {
        for (j = 0; j <= g->map->h; j += g->tiles->water->h + g->c->zoom) {
            stretch_sprite(g->map, g->tiles->water, i, j, g->tiles->water->w + g->c->zoom, g->tiles->water->h + g->c->zoom);
        }
    }
    blit(g->map, g->buffer, 0, 0, 0, 0, g->map->w, g->map->h);
}


/********************************
REDESSINE LA TOTALITÉ DE LA CARTE
********************************/
void jg_reload_all(_generale *g) {
    clear_bitmap(g->map);
    jg_paint_water(g);
    jg_paint_ground(g);
    jg_draw_grid(g, g->c->scroll_x, g->c->scroll_y, g->c->zoom);
    jg_display_toolbox(g, g->t->origin_x, g->t->origin_y);
    jg_display_menu(g);
    jg_display_all(g);
}
