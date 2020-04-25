//
//  grille.h
//  2048
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"

//Creer la grille de jeu
int **Creer_Grille(void){
    //Creer une grille
    int **grille = malloc(sizeof(int*) * SIZE);
    int i,j;
    for(i = 0;i < SIZE;i++) grille[i] = (int*)malloc(sizeof(int) * SIZE);
    
    //Initialiser la grille
    for(i = 0;i < SIZE;i++){
        for(j = 0;j < SIZE;j++){
            grille[i][j] = 0;
        }
    }
    
    //Générer la première initiale 2
    int a = rand() % SIZE;
    int b = rand() % SIZE;
    grille[a][b] = 2;
    
    //Générez le deuxième 2 initial mais pas dans la même ligne et colonne que le premier
    int c = rand() % SIZE;
    int d = rand() % SIZE;
    while(c == a){
        c = rand() % SIZE;
    }
    while(d == b){
        d = rand() % SIZE;
    }
    grille[c][d] = 2;
    
    //Retour à la grille de jeu initiale générée
    return grille;
}

//Affiche la grille de jeu
void Affiche_Grille(int **grille){
    int i,j;
    for(i = 0;i < SIZE;i++){
        for(j = 0;j < SIZE;j++){
            //Selon le nombre de chiffres à afficher, le mode d'affichage est différent
            if (grille[i][j] >= 0 && grille[i][j] < 10){
                printf("   %d  ",grille[i][j]);
            }else if (grille[i][j] > 10 && grille[i][j] < 100){
                printf("  %d  ",grille[i][j]);
            }else if (grille[i][j] > 100 && grille[i][j] < 1000){
                printf(" %d  ",grille[i][j]);
            }else{
                printf("%d  ",grille[i][j]);
            }
        }
        printf("\n");
    }
}

//Libérer la grille de jeu
void Free_Grille(int **grille){
    for(int i = 0;i < SIZE;i++) {
        free(grille[i]);
    }
    free(grille);
}
