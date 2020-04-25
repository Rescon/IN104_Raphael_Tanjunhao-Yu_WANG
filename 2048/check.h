//
//  check.h
//  2048
//

#ifndef check_h
#define check_h

//Liste des états de jeu possibles après chaque tour
enum end {go_on, win, lose};

//Calculez le nombre de positions libres dans le jeu actuel
int Count_Empty(int **grille);

//Déterminer le résultat du jeu actuel
enum end Result_Game(int **grille);

#endif /* check_h */
