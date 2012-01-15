/**
    ECE_CITY 2012
    utilities.c
    � Jean Guyomarc'h � Maxime Jumeline�� Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"

/*****************************
CR�ATION S�CURIS�E DES BITMAPS
*****************************/
BITMAP* jg_create_bitmap(int width, int height) {
    // Allocation de la bitmap
    BITMAP *tmp = create_bitmap(width, height);

    // Test : l'allocation a-t-elle r�ussi ?
    if (!tmp) {
        allegro_message("Echec lors de la creation de la BITMAP de dimentions (%i,%i)...ABORTING NOW!", width, height);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Nettoyage de la BITMAP : mise � (0, 0, 0) des pixels
    clear_bitmap(tmp);

    return tmp;
}

/*************************************************
CHARGEMENT S�CURIS� DE BITMAP � PARTIR D'UNE IMAGE
*************************************************/
BITMAP* jg_load_bitmap(const char *path) {
    // Chargement standard de la bitmap
    BITMAP *bmp = load_bitmap(path, NULL);

    // Test : la cr�ation a-t-elle r�ussi ?
    if (!bmp) {
        allegro_message("Creation de la BITMAP a partir du fichier %s impossible...ABORTING NOW!", path);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    return bmp;
}

/******************************
ALLOCATION S�CURIS�E DE M�MOIRE
******************************/
void* jg_malloc(size_t size) {
    // Allocation standard
    void *pt = malloc(size);

    // V�rification du malloc
    if (pt == NULL) {
        allegro_message("Probleme d'allocation du pointeur de taille %i...ABORTING NOW!", size);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    return pt;
}

/**************************************
AFFICHAGE � L'�CRAN DE LA BITMAP BUFFER
**************************************/
void jg_display_all(_generale *g) {
    blit(g->buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}

