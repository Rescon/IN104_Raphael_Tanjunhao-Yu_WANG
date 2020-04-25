//
//  main.c
//  2048
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "grille.h"
#include "move.h"
#include "check.h"
#include "appear.h"


int main(int argc, char const *argv[])
{
    //Générer une graine de nombre aléatoire liée à l'horloge
    srand((unsigned)time(NULL));
    
    //Créer la grille de jeu initiale générée
	int** grille = Creer_Grille();
    if(grille == NULL){
        printf("Le jeu n'a pas pu s'initialiser.\n");
        return -1;
    }else{
        printf("   Bienvenue en 2048.\n");
    }
    
    //Enregistrer le nombre de tours de jeu
    int tour = 1;
    printf("         Tour %d\n", tour);
    Affiche_Grille(grille);
    
    //Enregistrer les résultats du jeu après chaque tour
    enum end result = Result_Game(grille);
    
    bool operation_result = false;
    
    
    char operation;
    
    
    //Jouez à chaque tour
    while(result == go_on){
        tour++;
        
        //Enregistrer les actions choisies par le joueur
        printf("Veuillez faire votre opération[w(haut), a(gauche), s(bas) et d(droite)]:");
        scanf(" %c", &operation);
        
        //Lorsque l'entrée est illégale, le joueur doit entrer à nouveau
        while((operation != 'w')&&(operation != 'a')&&(operation != 's')&&(operation !='d')){
            printf("Vous devez entrer l'un des w(haut), a(gauche), s(bas) et d(droite):");
            scanf(" %c", &operation);
        }
        
        //Fonctionne selon le choix du joueur
        switch(operation){
            case 'w':
                operation_result = Move_Up(grille);
                break;
            case 'a':
                operation_result = Move_Left(grille);
                break;
            case 's':
                operation_result = Move_Down(grille);
                break;
            case 'd':
                operation_result = Move_Right(grille);
                break;
        }
        
        //Génère aléatoirement un 2 (75%) ou un 4 (25%) en position libre lorsque l'opération change de grille
        if(operation_result){
            Random_Appear(grille);
        }
        
        //Afficher la grille de jeu actuel et enregistrer les résultats
        printf("         Tour %d\n", tour);
        Affiche_Grille(grille);
        result = Result_Game(grille);
    }
    
    //Déterminer le résultat du jeu
    if(result == win){
        printf("Félicitations pour votre victoire!");
    }else{
        printf("Désolé, vous avez perdu le jeu, revenez.");
    }
    
    //Libérer la grille de jeu
    Free_Grille(grille);
    
	return 0;
}
