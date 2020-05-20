//
//  check.c
//  2048
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "check.h"
#include "grille.h"

//Calculez le nombre de positions libres dans le jeu actuel.
int Count_Empty(int **grille){
    int count = 0;
    int i,j;
    for (i = 0;i < SIZE; i++){
        for(j = 0;j < SIZE;j++){
            if (grille[i][j]==0){
                count++;
            }
        }
    }
    return count;
}

//Déterminez s'il y a le même nombre au-dessus et au-dessous de chaque nombre, renvoyez True s'il y en a et False sinon.
bool Find_Pair_UpDown(int** grille){
    int i,j;
    for (j = 0;j < SIZE;j++){
        for (i = 0;i < SIZE-1;i++){
            if (grille[i][j] == grille[i+1][j]){
                return true;
            }
        }
    }
    return false;
}

//Déterminez si les côtés gauche et droit de chaque numéro ont le même numéro, renvoyez True s'il y en a et False sinon.
bool Find_Pair_LeftRight(int **grille){
    int i,j;
    for(i = 0;i < SIZE;i++){
        for (j = 0;j < SIZE-1;j++){
            if(grille[i][j] == grille[i][j+1]){
                return true;
            }
        }
    }
    return false;
}

enum end Result_Game(int **grille){
    //S'il n'y a pas de position libre dans le jeu en cours et qu'il n'y a pas le même numéro en haut, en bas, à gauche et à droite de tous les numéros, il est jugé comme un échec.
    if (Count_Empty(grille) == 0){
        if (!(Find_Pair_LeftRight(grille) || Find_Pair_UpDown(grille))){
            return lose;
        }
    }
    
    //Si 2048 apparaît, il est jugé comme une victoire.
    for(int i = 0;i < SIZE;i++){
        for(int j = 0;j < SIZE;j++){
            if(grille[i][j] == 2048){
                return win;
            }
        }
    }
    
    //S'il n'y a ni victoire ni défaite, continuez le jeu.
    return go_on;
}
