/**
    ECE_CITY 2012
    defined.h
    � Jean Guyomarc'h � Maxime Jumeline�� Xavier Brun
**/

#ifndef DEFINED_H_INCLUDED
#define DEFINED_H_INCLUDED


/**
    CE FICHIER CONTIENT L'INT�GRALIT� DES DEFINE
    DE PR�PROCESSEUR, N�CESSAIRE � LA CONSTRUCTION
    GRAPHIQUE DU PROJET.
**/

#define WINDOW_W 800
#define WINDOW_H 600

#define PA_W 700
#define PA_H 580

#define MAP_W_H 600

#define OFFSET_X -80

#define PAS_X 16
#define PAS_Y 10

#define LOS_W 16    // Losange
#define LOS_H 10

/// Pour l'esprit, on cr�e le type BOOL, qui agira comme un bool�en (1 octet au lieu de 4 pour l'int) et qui est plus joli que char...
typedef char BOOL;

#endif // DEFINED_H_INCLUDED
