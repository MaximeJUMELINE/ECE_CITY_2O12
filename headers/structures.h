/**
    ECE_CITY 2012
    structures.h
    � Jean Guyomarc'h � Maxime Jumeline�� Xavier Brun
**/

#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED


/**
    CE FICHIER CONTIENT L'INT�GRALIT� DES STRUCTURES
    UTILIS�ES DANS LE PROJET.
**/


/********************************************************
STRUCTURE QUI CONTR�LE LE SCROLLING ET LE ZOOM DU TERRAIN
********************************************************/
typedef struct structure_view_controller {
    int scroll_x;           // Facteur de scroll en abscisses
    int scroll_y;           // Facteur de scroll en ordonn�es
    int zoom;               // Facteur de zoom
} _viewController;


/*************************************************************
STRUCTURE GLOBALE QUI CONTIENT TOUTES LES INFORMATIONS VITALES
*************************************************************/
typedef struct structure_generale {
    BITMAP *map;            // Le terrain jouable
    BITMAP *menu;           // La barre des menus
    _viewController *c;     // Contr�leur du scroll et du zoom
} _generale;
#endif // STRUCTURES_H_INCLUDED
