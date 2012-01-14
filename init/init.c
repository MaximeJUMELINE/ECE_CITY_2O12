/**
    ECE_CITY 2012
    init.c
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"


/***********************************
INITIALISATION DES PROCESSUS ALLEGRO
***********************************/
void jg_allegro_init(void) {
    // Initialisation des routines allegro
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());

    // Création sécurisée du mode graphique
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Initialisation interrompue : preferences graphiques incorrectes...ABORTING NOW!");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Intitulé de la fenêtre
    set_window_title("ECE City 2O12");

    // Afficher la souris
    show_mouse(screen);
}


/**************************************************
INITIALISATION DES RESSOURCES EXTÉRIEURES À ALLEGRO
**************************************************/
_generale* jg_init(void) {
    // Structure globale en elle-même
    _generale *g = (_generale *)jg_malloc(sizeof(_generale));

    // BITMAP de la carte de jeu
    g->map = jg_create_bitmap(800, 600);

    // Contrôleur de zoom et de scroll
    g->c = (_viewController *)jg_malloc(sizeof(_viewController));
    g->c->scroll_x = 0;
    g->c->scroll_y = 0;
    g->c->zoom = 0;

    return g;
}
