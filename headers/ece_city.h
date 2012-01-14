/**
    ECE_CITY 2012
    ece_city.h
    � Jean Guyomarc'h � Maxime Jumeline�� Xavier Brun
**/

#ifndef ECE_CITY_H_INCLUDED
#define ECE_CITY_H_INCLUDED

/**
    CE FICHIER CONTIENT L'INT�GRALIT� DES PROTOTYPES
    DES FONCTIONS D�VELOPP�ES POUR CE PROJET, OU �TANT
    DES R��CRITURES DE FONCTIONS D�J� EXISTANTES DANS
    LES BIBLIOTH�QUES STANDARD.
**/


/*************************
FONCTIONS D'INITIALISATION
*************************/
void jg_allegro_init(void);                 // Initialise pleinement Allegro, et de mani�re s�curis�e
_generale* jg_init(void);                   // Initialise la structure g�n�rale

/*********
SURCOUCHES
*********/
BITMAP* jg_create_bitmap(int, int);         // Cr��e une BITMAP de mani�re totalement s�curis�e
void* jg_malloc(size_t);                    // Allocation de m�moire s�curis�e

/*****************************
FONCTION DE DESSIN DE LA CARTE
*****************************/
void jg_draw_grid(_generale *, int, int, int);
void jg_zoom_controller(_generale *);
void jg_scroll_controller(_generale *);

#endif // ECE_CITY_H_INCLUDED
