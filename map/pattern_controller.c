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
    if (mouse_x > 0 && mouse_x <= 25) {
        g->c->scroll_x += 1;
        jg_draw_grid(g, g->c->scroll_x, g->c->scroll_y, g->c->zoom);
        clear_bitmap(g->map);
    }

    /// Scroll vers la droite
    if (mouse_x >= g->map->w - 25 && mouse_x < g->map->w) {
        g->c->scroll_x -= 1;
        jg_draw_grid(g, g->c->scroll_x, g->c->scroll_y, g->c->zoom);
        clear_bitmap(g->map);
    }

    /// Scroll vers le haut
    if (mouse_y > 0 && mouse_y <= 25) {
        g->c->scroll_y += 1;
        jg_draw_grid(g, g->c->scroll_x, g->c->scroll_y, g->c->zoom);
        clear_bitmap(g->map);
    }

    /// Scroll vers le bas
    if (mouse_y >= g->map->h - 25 && mouse_x < g->map->h) {
        g->c->scroll_y -= 1;
        jg_draw_grid(g, g->c->scroll_x, g->c->scroll_y, g->c->zoom);
        clear_bitmap(g->map);
    }
}

/**************************
ZOOMER OU DÉZOOMER LA CARTE
**************************/
void jg_zoom_controller(_generale *g) {
    if (mouse_b&1 && g->c->zoom < 10) {
        g->c->zoom += 1;
        g->c->scroll_x = -400;
        g->c->scroll_y = -400;
        clear_bitmap(g->map);
        jg_draw_grid(g, g->c->scroll_x, g->c->scroll_y, g->c->zoom);
    }

    if (mouse_b&2 && g->c->zoom > 0) {
        g->c->zoom -= 1;
        g->c->scroll_x = 0;
        g->c->scroll_y = 0;
        clear_bitmap(g->map);
        jg_draw_grid(g, g->c->scroll_x, g->c->scroll_y, g->c->zoom);
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
      //  if (j > g->map->h + 50*zoom) break;
    }

    // Nouvelle initialisation
    j = g->map->h/2 + 50*zoom;

    // Dessin des lignes obliques de la gauche vers le haut
    for (i = OFFSET_X + scroll_w; i <= g->map->w/2 + scroll_w + 50*zoom; i+= LOS_W/2 + zoom) {
        line(g->map, i + scroll_w, j + scroll_h, i + g->map->w/2+50*zoom - OFFSET_X + scroll_w, j + g->map->h/2+50*zoom + scroll_h, makecol(255, 255, 255));

        // Gestion d'un compteur interne (simulation de boucle for simulténée)
        j -= LOS_H/2 + zoom;
        if (j < -50*zoom) break;
    }

    // Affichage à l'écran de la grille
    blit(g->map, screen, 0, 0, 0, 0, g->map->w, g->map->h);
}
