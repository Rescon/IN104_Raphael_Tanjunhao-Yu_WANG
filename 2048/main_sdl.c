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
    
    //Déterminer l'événement du clavier et enregistrer les valeurs d'entrée du clavier.
    SDL_Event event;
    SDLKey operation;
    int continuer;
    
    //Jouez à chaque tour
    while(result == go_on){
        //Si la valeur d'entrée du clavier n'est pas dans la valeur spécifiée, continuez d'attendre l'entrée.
        continuer = 1;
        while(continuer){
            SDL_WaitEvent(&event);
            switch(event.type){
                case SDL_QUIT:
                    printf("Vous avez forcé la fin du jeu.\n");
                    Free_Grille(grille);
                    free(image);
                    SDL_Quit();
                    return EXIT_SUCCESS;                  

                //L'événement du clavier
                case SDL_KEYUP:
                    operation = event.key.keysym.sym;
                    switch(operation){

                        //Fonctionne selon le choix du joueur
		        case SDLK_UP:
                        case SDLK_w:
                            operation_result = Move_Up(grille);
                            continuer = 0;
                            break;
			case SDLK_LEFT:
                        case SDLK_a:
                            operation_result = Move_Left(grille);
                            continuer = 0;
                            break;
			case SDLK_DOWN:
                        case SDLK_s:
                            operation_result = Move_Down(grille);
                            continuer = 0;
                            break;
			case SDLK_RIGHT:
                        case SDLK_d:
                            operation_result = Move_Right(grille);
                            continuer = 0;
                            break;

                        //Appuyez sur ESC pour quitter
                        case SDLK_ESCAPE:
                            printf("Vous avez forcé la fin du jeu.\n");
                            Free_Grille(grille);
                            free(image);
                            SDL_Quit(); 
                            return EXIT_SUCCESS;

                        //En attente de la prochaine entrée
                        default:
                            break;
                        }


            }
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