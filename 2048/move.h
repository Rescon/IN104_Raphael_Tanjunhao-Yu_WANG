//
//  move.h
//  2048
//

#ifndef move_h
#define move_h
#include <stdbool.h>

//L'opération correspondante “haut”, retourner false s'il n'y a pas de changement de la grille
bool Move_Up(int **grille);

//L'opération correspondante “bas”, retourner false s'il n'y a pas de changement de la grille
bool Move_Down(int **grille);

//L'opération correspondante “gauche”, retourner false s'il n'y a pas de changement de la grille
bool Move_Left(int **grille);

//L'opération correspondante “droite”, retourner false s'il n'y a pas de changement de la grille
bool Move_Right(int **grille);

#endif /* move_h */
