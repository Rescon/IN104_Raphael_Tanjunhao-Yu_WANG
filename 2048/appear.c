//
//  appear.c
//  2048
//

#include <stdio.h>
#include <stdlib.h>
#include "appear.h"
#include "grille.h"
#include "check.h"

//Trouvez les positions libres et retournez leur index
struct position *Find_Empty_Position(int **grille){
    struct position *position_empty = NULL;
    int num = Count_Empty(grille);
    if(num > 0){
        position_empty = malloc(sizeof(struct position) * num);
        int i,j,k = 0;
        for(i = 0;i < SIZE;i++){
            for (j = 0;j < SIZE;j++){
                if(grille[i][j] == 0){
                    position_empty[k].x = i;
                    position_empty[k].y = j;
                    k++;
                }
            }
        }
    }
    return position_empty;
}

//Génère aléatoirement un 2 (75%) ou un 4 (25%) en position libre
void Random_Appear(int **grille){
    struct position *position_empty = Find_Empty_Position(grille);
    int num = Count_Empty(grille);
    
    //Décidé de générer de nouveaux numéros dans les premières positions libres
    int a = rand() % num;
    
    //Décidez de générer 2 ou 4
    int b = rand() % 4; //%25 appears 4
    
    //Générer des numéros sélectionnés à des emplacements sélectionnés
    if(b == 0){
        grille[position_empty[a].x][position_empty[a].y] = 4;
    }else{
        grille[position_empty[a].x][position_empty[a].y] = 2;
    }
    
    free(position_empty);
}
