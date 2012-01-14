/**
    ECE_CITY 2012
    ece_city.h
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#ifndef ECE_CITY_H_INCLUDED
#define ECE_CITY_H_INCLUDED

/**
    CE FICHIER CONTIENT L'INTÉGRALITÉ DES PROTOTYPES
    DES FONCTIONS DÉVELOPPÉES POUR CE PROJET, OU ÉTANT
    DES RÉÉCRITURES DE FONCTIONS DÉJÀ EXISTANTES DANS
    LES BIBLIOTHÈQUES STANDARD.
**/


/*************************
FONCTIONS D'INITIALISATION
*************************/
void jg_allegro_init(void);                 // Initialise pleinement Allegro, et de manière sécurisée
_generale* jg_init(void);                   // Initialise la structure générale

/*********
SURCOUCHES
*********/
BITMAP* jg_create_bitmap(int, int);         // Créée une BITMAP de manière totalement sécurisée
void* jg_malloc(size_t);                    // Allocation de mémoire sécurisée

/*****************************
FONCTION DE DESSIN DE LA CARTE
*****************************/
void jg_draw_grid(_generale *, int, int, int);
void jg_zoom_controller(_generale *);
void jg_scroll_controller(_generale *);

#endif // ECE_CITY_H_INCLUDED
