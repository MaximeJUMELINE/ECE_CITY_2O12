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
void jg_allegro_init(void);                    // Initialise pleinement Allegro, et de manière sécurisée
_generale* jg_init(void);                      // Initialise la structure générale
void jg_font_init(_generale *);                // Chargement de la police

/*********
SURCOUCHES
*********/
BITMAP* jg_create_bitmap(int, int);         // Créée une BITMAP de manière totalement sécurisée
BITMAP* jg_load_bitmap(const char *);       // Charge une BITMAP de manière sécurisée
void* jg_malloc(size_t);                    // Allocation de mémoire sécurisée

/*****************************
FONCTION DE DESSIN DE LA CARTE
*****************************/
void jg_draw_grid(_generale *, int, int, int);      // Dessine la grille de terrain
void jg_zoom_controller(_generale *);               // Répondeur d'événement de zoom
void jg_scroll_controller(_generale *);             // Répondeur d'événement de scroll

/********************************
CONTRÔLEURS DE LA BARRE DES MENUS
********************************/
void jg_menu_controller(_generale *);           // Répondeur d'événement du menu
void jg_draw_menu(_generale *);                 // Dessine le menu initial

/**********************
CONTRÔLEURS D'AFFICHAGE
**********************/
void jg_display_all(_generale *);                   // Affiche à l'écran
void jg_display_menu(_generale *);                  // Colle le menu sur le BUFFER !!
void jg_display_menuitem(_generale *);              // Colle les bouts de menus sur le BUFFER DU MENU !!
void jg_display_toolbox(_generale *, int, int);     // Recompose la toolbox sur le BUFFER DE LA TOOLBOX
void jg_reload_all(_generale *);                    // Redessine la totalité des acteurs graphiques

/*************************************
RESPONSABLE DES CHARGEMENTS DE DONNÉES
*************************************/
void jg_load_menu(_generale *);                 // Charge les images du menu
void jg_load_toolbox(_generale *);              // Charge les images de la toolbox
void jg_load_tiles(_generale *);                // Charge les tuiles

/*******
TOOLBOX
*******/
void jg_toolbox_controller(_generale *);        // Répondeur d'événements de la toolbox aux clics
void jg_draw_toolbox(_generale *);              // Redessine la toolbox originale
void jg_drag_toolbox(_generale *);              // Répondeur d'événement de la toolbox au Drag And Drop

/*****************
DESSINE LES TUILES
*****************/
void jg_paint_water(_generale *);
void jg_paint_ground(_generale *);


#endif // ECE_CITY_H_INCLUDED
