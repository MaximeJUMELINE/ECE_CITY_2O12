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
    LE TYPE � BOOL � A �T� D�FINI DANS DEFINED.H
**/


/********************************************************
STRUCTURE QUI CONTR�LE LE SCROLLING ET LE ZOOM DU TERRAIN
********************************************************/
typedef struct structure_view_controller {
    int scroll_x;           // Facteur de scroll en abscisses
    int scroll_y;           // Facteur de scroll en ordonn�es
    int zoom;               // Facteur de zoom
} _viewController;


/****************
STRUCTURE DU MENU
****************/
typedef struct structure_menu {
    BITMAP *menubuffer;     // Buffer pour le menu
    BITMAP *menu;           // La barre des menus
    BITMAP *menu0;          // Quand � Menu � est survol�
    BITMAP *menu1;          // Quand � Fichier � est survol�
    BITMAP *menu2;          // Quand � Vitesses � est survol�
    BITMAP *menu3;          // Quand � Options � est survol�
    BITMAP *menu1_0;        // Nouvelle ville
    BITMAP *menu1_1;        // Charger ville
    BITMAP *menu1_2;        // Sauvegarde ville
    BITMAP *menu1_3;        // Info
    BITMAP *menu1_4;        // Quitter
    BITMAP *menu2_0;        // Pause
    BITMAP *menu2_1;        // Tortue
    BITMAP *menu2_2;        // Lama
    BITMAP *menu2_3;        // Gu�pard
    BITMAP *menu3_0;        // Effets sonores
    BITMAP *menu3_1;        // Musiques
    BITMAP *check_on;       // Est s�lectionn�, et non survol�
    BITMAP *check_off;      // Est s�lectionn�, et survol�

    BOOL canClickOnMenu;    // Si on peut cliquer sur un menu d�filant
    BOOL onClick;           // Si on vient juste d'entrer dans une zone sp�ciale
} _menu;


/**********************
STRUCTURE DE LA TOOLBOX
**********************/
typedef struct structure_toolbox {
    /// Caract�ristiques
    BITMAP *toolbox;          // La BITMAP de la bo�te � outils
    BITMAP *buffer;           // Buffer pour les op�rations de superpositions
    int origin_x;             // Origine en X
    int origin_y;             // Origine en Y
    BOOL isCatch;             // Drag&Drop de la fen�tre ?

    /// Ic�nes cliqu�es
    BITMAP *scroll_up;        // Scroll vers le haut
    BITMAP *scroll_down;      // Scroll vers le bas
    BITMAP *scroll_right;     // Scroll vers la droite
    BITMAP *scroll_left;      // Scroll vers la gauche
    BOOL onDeactivate;        // Retirer l'effet de clic des ic�nes de la barre
} _toolbox;


/********************************
STRUCTURE DE POLICE PERSONNALIS�E
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

/***************
PAGE INFORMATION
***************/
typedef struct structure_info {
    int origin_x;             // Origine en X
    int origin_y;             // Origine en Y
    BITMAP *page_info;        // Image du contenu de la page d'information
} _info;

/**********************************
PAGE DE SAUVEGARDE OU DE CHARGEMENT
**********************************/
typedef struct structure_save_load {
    int origin_x;             // Origine en X
    int origin_y;             // Origine en Y

} _save_load;

/*************************************************************
STRUCTURE GLOBALE QUI CONTIENT TOUTES LES INFORMATIONS VITALES
*************************************************************/
typedef struct structure_generale {
    BITMAP *buffer;         // La BITMAP qui sera blitt�e sur l'�cran, et qui est compos�e de chaque �tape
    BITMAP *map;            // Le terrain jouable
    _menu *m;               // Le menu et ses composantes
    _viewController *c;     // Contr�leur du scroll et du zoom
    _toolbox *t;            // La toolbox
    _font *font;            // La police personnalis�e
    _tiles *tiles;          // Les tuiles
    _info *info;            // La page information
    _save_load *sl_page     // La page de chargement OU de sauvegarde (meme buffer)
} _generale;

#endif // STRUCTURES_H_INCLUDED
