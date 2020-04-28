//
//  move.c
//  2048
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "move.h"
#include "grille.h"

//Déterminer si deux grilles sont égales
bool Is_Equal(int **grille_1, int **grille_2){
    int i,j;
    for(i = 0;i < SIZE;i++){
        for(j = 0;j < SIZE;j++){
            if(grille_1[i][j] != grille_2[i][j]){
                return false;
            }
        }
    }
    return true;
}

//Copier le contenu dans la grille
int **Copy_Grille(int **grille){
    int **a = malloc(sizeof(int*) * SIZE);
    int i,j;
    for(i = 0;i < SIZE;i++) a[i] = (int*)malloc(sizeof(int) * SIZE);
    for(i = 0;i < SIZE;i++){
        for(j = 0;j < SIZE;j++){
            a[i][j] = grille[i][j];
        }
    }
    return a;
}

//L'opération correspondante “haut”,, retourner false s'il n'y a pas de changement de la grille
bool Move_Up(int **grille){
    //Utilisez un pour stocker le contenu dans la grille avant l'opération
    int **a = Copy_Grille(grille);
    
    int i,j,k;
    for(j = 0;j < SIZE;j++){
        //Ajoutez les nombres égaux dans la même colonne qui sont adjacents (seul 0 au milieu est également considéré comme adjacent) et mettez-les en position supérieure, et les nombres correspondants en position inférieure reviennent à zéro.
        for (i = 0;i < SIZE - 1;i++){
            if(grille[i][j] != 0){
                for(k = i + 1;k  < SIZE;k++){
                    if(grille[k][j] != 0){
                        if(grille[i][j] == grille[k][j]){
                            grille[i][j] += grille[k][j];
                            grille[k][j] = 0;
                        }
                        break;
                    }
                }
            }
        }
        
        //Faites glisser tous les chiffres vers le haut.
        for (i = 0;i < SIZE - 1;i++){
            if(grille[i][j] == 0){
                for(k = i + 1;k < SIZE;k++){
                    if(grille[k][j] != 0){
                        grille[i][j] = grille[k][j];
                        grille[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    //Comparer si la grille a changé avant et après l'opération
    if(Is_Equal(a, grille)){
        free(a);
        return false;
    }else{
        free(a);
        return true;
    }
}

//L'opération correspondante “bas”, retourner false s'il n'y a pas de changement de la grille
bool Move_Down(int **grille){
    //Utilisez un pour stocker le contenu dans la grille avant l'opération
    int **a = Copy_Grille(grille);
    
    int i,j,k;
    for(j = 0;j < SIZE;j++){
        //Ajoutez les nombres égaux dans la même colonne qui sont adjacents (seul 0 au milieu est également considéré comme adjacent) et mettez-les en position inférieure, et les nombres correspondants en position supérieure reviennent à zéro.
        for (i = SIZE - 1;i > 0;i--){
            if(grille[i][j] != 0){
                for(k = i - 1;k >= 0;k--){
                    if(grille[k][j] != 0){
                        if(grille[i][j] == grille[k][j]){
                            grille[i][j] += grille[k][j];
                            grille[k][j] = 0;
                        }
                        break;
                    }
                }
            }
        }
        
        //Faites glisser tous les chiffres vers le bas
        for (i = SIZE - 1;i > 0;i--){
            if(grille[i][j] == 0){
                for(k = i - 1;k >= 0;k--){
                    if(grille[k][j] != 0){
                        grille[i][j] = grille[k][j];
                        grille[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    //Comparer si la grille a changé avant et après l'opération
    if(Is_Equal(a, grille)){
        free(a);
        return false;
    }else{
        free(a);
        return true;
    }
}

//L'opération correspondante “gauche”, retourner false s'il n'y a pas de changement de la grille
bool Move_Left(int **grille){
    //Utilisez un pour stocker le contenu dans la grille avant l'opération
    int **a = Copy_Grille(grille);
    
    int i,j,k;
    for(i = 0;i < SIZE;i++){
        //Ajoutez les nombres égaux dans la même ligne qui sont adjacents (seul 0 au milieu est également considéré comme adjacent) et mettez-les sur le côté gauche, et les nombres correspondants sur le côté droit reviennent à zéro
        for (j = 0;j < SIZE-1;j++){
            if(grille[i][j] != 0){
                for(k = j + 1;k  < SIZE;k++){
                    if(grille[i][k] != 0){
                        if(grille[i][j] == grille[i][k]){
                            grille[i][j] += grille[i][k];
                            grille[i][k] = 0;
                        }
                        break;
                    }
                }
            }
        }
        //Faites glisser tous les chiffres vers la gauche
        for (j = 0;j < SIZE - 1;j++){
            if(grille[i][j] == 0){
                for(k = j + 1;k < SIZE;k++){
                    if(grille[i][k] != 0){
                        grille[i][j] = grille[i][k];
                        grille[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    //Comparer si la grille a changé avant et après l'opération
    if(Is_Equal(a, grille)){
        free(a);
        return false;
    }else{
        free(a);
        return true;
    }
}

//L'opération correspondante “droite”, retourner false s'il n'y a pas de changement de la grille
bool Move_Right(int **grille){
    //Utilisez un pour stocker le contenu dans la grille avant l'opération
    int **a = Copy_Grille(grille);
    
    int i,j,k;
    for(i = 0;i < SIZE;i++){
        //Ajoutez les nombres égaux dans la même ligne qui sont adjacents (seul 0 au milieu est également considéré comme adjacent) et mettez-les sur le côté droit, et les nombres correspondants sur le côté gauche reviennent à zéro
        for (j = SIZE - 1;j > 0;j--){
            if(grille[i][j] != 0){
                for(k = j - 1;k >= 0;k--){
                    if(grille[i][k] != 0){
                        if(grille[i][j] == grille[i][k]){
                            grille[i][j] += grille[i][k];
                            grille[i][k] = 0;
                        }
                        break;
                    }
                }
            }
        }
        
        //Faites glisser tous les chiffres vers la droite
        for (j = SIZE - 1;j > 0;j--){
            if(grille[i][j] == 0){
                for(k = j - 1;k >= 0;k--){
                    if(grille[i][k] != 0){
                        grille[i][j] = grille[i][k];
                        grille[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    //Comparer si la grille a changé avant et après l'opération
    if(Is_Equal(a, grille)){
        free(a);
        return false;
    }else{
        free(a);
        return true;
    }
}

