//
//  evalue.h
//  2048
//

#ifndef evalue_h
#define evalue_h
#include <stdbool.h>

//Compte le nombre de groupes isolés.
double Islands(int** grille);

//Mesurez la fluidité de la grille
double Smooth(int** grille);

//Fonction d'évaluation statique
double Evalue(int** grille);

#endif /* evalue_h */