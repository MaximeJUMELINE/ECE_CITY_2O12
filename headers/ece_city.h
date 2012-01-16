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
void jg_allegro_init(void);                    // Initialise pleinement Allegro, et de mani�re s�curis�e
_generale* jg_init(void);                      // Initialise la structure g�n�rale
void jg_font_init(_generale *);                // Chargement de la police

/*********
SURCOUCHES
*********/
BITMAP* jg_create_bitmap(int, int);         // Cr��e une BITMAP de mani�re totalement s�curis�e
BITMAP* jg_load_bitmap(const char *);       // Charge une BITMAP de mani�re s�curis�e
void* jg_malloc(size_t);                    // Allocation de m�moire s�curis�e

/*****************************
FONCTION DE DESSIN DE LA CARTE
*****************************/
void jg_draw_grid(_generale *, int, int, int);      // Dessine la grille de terrain
void jg_zoom_controller(_generale *);               // R�pondeur d'�v�nement de zoom
void jg_scroll_controller(_generale *);             // R�pondeur d'�v�nement de scroll

/********************************
CONTR�LEURS DE LA BARRE DES MENUS
********************************/
void jg_menu_controller(_generale *);           // R�pondeur d'�v�nement du menu
void jg_draw_menu(_generale *);                 // Dessine le menu initial

/**********************
CONTR�LEURS D'AFFICHAGE
**********************/
void jg_display_all(_generale *);                   // Affiche � l'�cran
void jg_display_menu(_generale *);                  // Colle le menu sur le BUFFER !!
void jg_display_menuitem(_generale *);              // Colle les bouts de menus sur le BUFFER DU MENU !!
void jg_display_toolbox(_generale *, int, int);     // Recompose la toolbox sur le BUFFER DE LA TOOLBOX
void jg_reload_all(_generale *);                    // Redessine la totalit� des acteurs graphiques
void mj_display_info(_generale *);                  // Appel de la page d'information
void mj_display_load(_generale *);                  // Appel la fonction de chargement d'une partie
void mj_display_save(_generale *);                  // Appel la fonction de sauvegarde d'une partie

/*************************************
RESPONSABLE DES CHARGEMENTS DE DONN�ES
*************************************/
void jg_load_menu(_generale *);                 // Charge les images du menu
void jg_load_toolbox(_generale *);              // Charge les images de la toolbox
void jg_load_tiles(_generale *);                // Charge les tuiles

/*******
TOOLBOX
*******/
void jg_toolbox_controller(_generale *);        // R�pondeur d'�v�nements de la toolbox aux clics
void jg_draw_toolbox(_generale *);              // Redessine la toolbox originale
void jg_drag_toolbox(_generale *);              // R�pondeur d'�v�nement de la toolbox au Drag And Drop

/*****************
DESSINE LES TUILES
*****************/
void jg_paint_water(_generale *);
void jg_paint_ground(_generale *);


#endif // ECE_CITY_H_INCLUDED
