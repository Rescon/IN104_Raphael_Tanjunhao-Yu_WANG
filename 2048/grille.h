//
//  grille.h
//  2048
//

#ifndef grille_h
#define grille_h

#define SIZE 4

//Creer la grille de jeu
int **Creer_Grille(void);

//Affiche la grille de jeu
void Affiche_Grille(int **grille);

//Libérer la grille de jeu
void Free_Grille(int **grille);

#endif /* grille_h */
