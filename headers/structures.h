/**
    ECE_CITY 2012
    structures.h
    © Jean Guyomarc'h — Maxime Jumeline — Xavier Brun
**/

#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED


/**
    CE FICHIER CONTIENT L'INTÉGRALITÉ DES STRUCTURES
    UTILISÉES DANS LE PROJET.
    LE TYPE « BOOL » A ÉTÉ DÉFINI DANS DEFINED.H
**/


/********************************************************
STRUCTURE QUI CONTRÔLE LE SCROLLING ET LE ZOOM DU TERRAIN
********************************************************/
typedef struct structure_view_controller {
    int scroll_x;           // Facteur de scroll en abscisses
    int scroll_y;           // Facteur de scroll en ordonnées
    int zoom;               // Facteur de zoom
} _viewController;


/****************
STRUCTURE DU MENU
****************/
typedef struct structure_menu {
    BITMAP *menubuffer;     // Buffer pour le menu
    BITMAP *menu;           // La barre des menus
    BITMAP *menu0;          // Quand « Menu » est survolé
    BITMAP *menu1;          // Quand « Fichier » est survolé
    BITMAP *menu2;          // Quand « Vitesses » est survolé
    BITMAP *menu3;          // Quand « Options » est survolé
    BITMAP *menu1_0;        // Nouvelle ville
    BITMAP *menu1_1;        // Charger ville
    BITMAP *menu1_2;        // Sauvegarde ville
    BITMAP *menu1_3;        // Info
    BITMAP *menu1_4;        // Quitter
    BITMAP *menu2_0;        // Pause
    BITMAP *menu2_1;        // Tortue
    BITMAP *menu2_2;        // Lama
    BITMAP *menu2_3;        // Guépard
    BITMAP *menu3_0;        // Effets sonores
    BITMAP *menu3_1;        // Musiques
    BITMAP *check_on;       // Est sélectionné, et non survolé
    BITMAP *check_off;      // Est sélectionné, et survolé

    BOOL canClickOnMenu;    // Si on peut cliquer sur un menu défilant
    BOOL onClick;           // Si on vient juste d'entrer dans une zone spéciale
} _menu;


/**********************
STRUCTURE DE LA TOOLBOX
**********************/
typedef struct structure_toolbox {
    /// Caractéristiques
    BITMAP *toolbox;          // La BITMAP de la boîte à outils
    BITMAP *buffer;           // Buffer pour les opérations de superpositions
    int origin_x;             // Origine en X
    int origin_y;             // Origine en Y
    BOOL isCatch;             // Drag&Drop de la fenêtre ?

    /// Icônes cliquées
    BITMAP *scroll_up;        // Scroll vers le haut
    BITMAP *scroll_down;      // Scroll vers le bas
    BITMAP *scroll_right;     // Scroll vers la droite
    BITMAP *scroll_left;      // Scroll vers la gauche
    BOOL onDeactivate;        // Retirer l'effet de clic des icônes de la barre
} _toolbox;


/********************************
STRUCTURE DE POLICE PERSONNALISÉE
********************************/
typedef struct structure_police {
    FONT *lucidaGrande;     // La police normale
    FONT *lucidaGrandeBold; // Police en gras
    PALETTE p;              // Palette de couleurs
} _font;


/*****
TUILES
*****/
typedef struct structure_tuiles {
    BITMAP *water;
    BITMAP *ground;
} _tiles;

/*************************************************************
STRUCTURE GLOBALE QUI CONTIENT TOUTES LES INFORMATIONS VITALES
*************************************************************/
typedef struct structure_generale {
    BITMAP *buffer;         // La BITMAP qui sera blittée sur l'écran, et qui est composée de chaque étape
    BITMAP *map;            // Le terrain jouable
    _menu *m;               // Le menu et ses composantes
    _viewController *c;     // Contrôleur du scroll et du zoom
    _toolbox *t;            // La toolbox
    _font *font;            // La police personnalisée
    _tiles *tiles;          // Les tuiles
} _generale;

#endif // STRUCTURES_H_INCLUDED
