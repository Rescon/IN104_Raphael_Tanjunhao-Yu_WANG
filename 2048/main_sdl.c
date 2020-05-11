//
// main_sdl.c
// 2048
// 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>

#include "grille.h"
#include "move.h"
#include "check.h"
#include "appear.h"
#include "affiche_sdl.h"

#define WINDOW_WIDTH (480)
#define WINDOW_HEIGHT (480)
#define SCREEEN_BPP (32)

int main(int argc, char const *argv[])
{
    //Générer une graine de nombre aléatoire liée à l'horloge
    srand((unsigned)time(NULL));

	// Initialisation de la SDL
    SDL_Init(SDL_INIT_VIDEO); 

    // Ouverture de la fenêtre
    SDL_Surface* ecran = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, SCREEEN_BPP, SDL_HWSURFACE); 

    //Charger toutes les images
    SDL_Surface** image = Load_Image();
    
    //Le processus de lecture de la saisie au clavier ne nécessite pas la touche Entrée et n'est plus affiché
    system("stty raw");
    system("stty -echo");

    //Créer la grille de jeu initiale générée
	int** grille = Creer_Grille();
    if(grille == NULL){
        printf("Le jeu n'a pas pu s'initialiser.\n");
        return -1;
    }else{
        printf("Bienvenue en 2048.\n");
    }
    
    Affiche_Grille_SDL(grille,ecran,image);
    
    //Enregistrer les résultats du jeu après chaque tour
    enum end result = Result_Game(grille);
    
    bool operation_result = false;
    
    char operation;
    
    
    //Jouez à chaque tour
    while(result == go_on){
        
        //Enregistrer les actions choisies par le joueur
        system("stty raw");
        system("stty -echo");
        operation = getchar();
        
        //Lorsque l'entrée est illégale, le joueur doit entrer à nouveau
        while((operation != 'w')&&(operation != 'a')&&(operation != 's')&&(operation !='d')){
        	operation = getchar();
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
        Affiche_Grille_SDL(grille,ecran,image);
        result = Result_Game(grille);
    }
    
    //Déterminer le résultat du jeu
    if(result == win){
        printf("Félicitations pour votre victoire!\n");
    }else{
        printf("Désolé, vous avez perdu le jeu, revenez.\n");
    }
    
    //Libérer la grille de jeu
    Free_Grille(grille);
    free(image);
 
 	// Arrêt de la SDL
    SDL_Quit(); 
 
 	// Fermeture du programme
    return EXIT_SUCCESS;
}