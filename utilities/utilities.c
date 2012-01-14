/**
    ECE_CITY 2012
    utilities.c
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"

/*****************************
CRÉATION SÉCURISÉE DES BITMAPS
*****************************/
BITMAP* jg_create_bitmap(int width, int height) {
    // Allocation de la bitmap
    BITMAP *tmp = create_bitmap(width, height);

    // Test : l'allocation a-t-elle réussi ?
    if (!tmp) {
        allegro_message("Echec lors de la creation de la BITMAP de dimentions (%i,%i)...ABORTING NOW!", width, height);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Nettoyage de la BITMAP : mise à (0, 0, 0) des pixels
    clear_bitmap(tmp);

    return tmp;
}


/******************************
ALLOCATION SÉCURISÉE DE MÉMOIRE
******************************/
void* jg_malloc(size_t size) {
    // Allocation standard
    void *pt = malloc(size);

    // Vérification du malloc
    if (pt == NULL) {
        allegro_message("Probleme d'allocation du pointeur de taille %i...ABORTING NOW!", size);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    return pt;
}
