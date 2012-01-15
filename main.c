/**
    ECE_CITY 2012
    main.c
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#include "headers/libraries.h"
#include "headers/defined.h"
#include "headers/structures.h"
#include "headers/ece_city.h"

int main(int argc, char **argv) {
    // Initialisation des routines allegro
    jg_allegro_init();

    // Initialisation des ressources externes
    _generale *g = jg_init();

    // Initialisation de la vue
    jg_draw_toolbox(g);

    /// Contrôleur événementiel
    while (!key[KEY_ESC]) {
        jg_zoom_controller(g);
        jg_scroll_controller(g);
        jg_display_toolbox(g, 0, 0);
        jg_toolbox_controller(g);
        jg_drag_toolbox(g);
        jg_menu_controller(g);
    } /* Fin du contrôleur événementiel. */

    // Fin planifiée du programme (pas d'erreur d'exécution)
    return EXIT_SUCCESS;
} END_OF_MAIN();
