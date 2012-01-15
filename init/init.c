/**
    ECE_CITY 2012
    init.c
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"


/***************************
INITIALISATION DES PROCESSUS
***************************/
void jg_allegro_init(void) {
    // Initialisation des routines allegro
    allegro_init();

    // Événements aléatoires
    srand(time(NULL));

    // Connexion du clavier et de la souris
    install_keyboard();
    install_mouse();

    // Profondeur colorimétrique
    set_color_depth(desktop_color_depth());

    // Création sécurisée du mode graphique
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, WINDOW_W, WINDOW_H, 0, 0) != 0) {
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
    /// Structure globale en elle-même
    _generale *g = (_generale *)jg_malloc(sizeof(_generale));

    /// Police
    g->font = (_font *)jg_malloc(sizeof(_font));
    jg_font_init(g);

    /// BITMAPS
    g->m = (_menu *)jg_malloc(sizeof(_menu));                       // Structure du menu
    g->buffer = jg_create_bitmap(WINDOW_W, WINDOW_H);   // Le buffer
    g->map = jg_create_bitmap(WINDOW_W, WINDOW_H);

    /// Menu
    g->m->menubuffer = jg_create_bitmap(WINDOW_W, 161);
    clear_to_color(g->m->menubuffer, makecol(255, 0, 255));
    jg_load_menu(g);
    g->m->canClickOnMenu = 0;
    g->m->onClick = 0;

    /// Contrôleur de zoom et de scroll
    g->c = (_viewController *)jg_malloc(sizeof(_viewController));
    g->c->scroll_x = 0;
    g->c->scroll_y = 0;
    g->c->zoom = 0;

    /// Toolbox
    g->t = (_toolbox *)jg_malloc(sizeof(_toolbox));
    jg_load_toolbox(g);
    g->t->buffer = jg_create_bitmap(100, 300);
    g->t->origin_x = WINDOW_W - g->t->toolbox->w - 10;
    g->t->origin_y = 40;
    g->t->onDeactivate = 0;

    /// Tuiles
    g->tiles = (_tiles *)jg_malloc(sizeof(_tiles));
    jg_load_tiles(g);

    return g;
}

/**************************
INITIALISATION DE LA POLICE
**************************/
void jg_font_init(_generale *g) {
    /// Chargement de Lucida Grande
    g->font->lucidaGrande = load_font("font/LucidaGrande.pcx", g->font->p, NULL);

    if (!g->font->lucidaGrande) {
        allegro_message("Impossible de charger la police Lucida Grande (fichier font/LucidaGrande.pcx)...ABORTING NOW!");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    /// Chargement de Lucida Grande (Bold)
    g->font->lucidaGrandeBold = load_font("font/LucidaGrandeBold.pcx", g->font->p, NULL);

    if (!g->font->lucidaGrandeBold) {
        allegro_message("Impossible de charger la police Lucida Grande (Bold) (fichier font/LucidaGrandeBold.pcx)...ABORTING NOW!");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
