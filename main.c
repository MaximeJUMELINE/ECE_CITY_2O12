/**
    ECE_CITY 2012
    main.c
    � Jean Guyomarc'h � Maxime Jumeline�� Xavier Brun
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

    // Trac� initial du quadrillage
    jg_draw_grid(g, 0, 0, 0);

    /// Contr�leur �v�nementiel
    while (!key[KEY_ESC]) {
        jg_zoom_controller(g);
        jg_scroll_controller(g);
    } /* Fin du contr�leur �v�nementiel. */

    // Fin planifi�e du programme (pas d'erreur d'ex�cution)
    return EXIT_SUCCESS;
} END_OF_MAIN();
