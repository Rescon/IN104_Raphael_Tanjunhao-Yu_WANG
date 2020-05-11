//
// affiche_sdl.c
// 2048
// 

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "affiche_sdl.h"
#include "grille.h"

//Affiche la grille de jeu
void Affiche_Grille_SDL(int** grille, SDL_Surface* ecran, SDL_Surface** image){
	int i,j;
	SDL_Surface* image_number = NULL;
	SDL_Rect position_image;

	for(i = 0;i < SIZE;i++){
		for(j = 0;j < SIZE;j++){
			switch (grille[i][j]){
				case 0: image_number = image[0];break;
				case 2: image_number = image[1];break;
				case 4: image_number = image[2];break;
				case 8: image_number = image[3];break;
				case 16: image_number = image[4];break;
				case 32: image_number = image[5];break;
				case 64: image_number = image[6];break;
				case 128: image_number = image[7];break;
				case 256: image_number = image[8];break;
				case 512: image_number = image[9];break;
				case 1024: image_number = image[10];break;
				case 2048: image_number = image[11];break;
			}

			//Calculez la position d'affichage correspondant à l'image
			position_image.x = j * 120;
			position_image.y = i * 120;

			//Collez l'image correspondante en arrière-plan
			SDL_BlitSurface(image_number, NULL, ecran, &position_image);
		}
	}

	//Actualiser l'écran
	SDL_Flip(ecran);
}

//Charger toutes les images
SDL_Surface** Load_Image(void){
	SDL_Surface** image = malloc(12*sizeof(SDL_Surface*));

	image[0] = IMG_Load("number/0.png");
   	if(!image[0]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

	image[1] = IMG_Load("number/2.png");
   	if(!image[1]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

	image[2] = IMG_Load("number/4.png");
   	if(!image[2]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

	image[3] = IMG_Load("number/8.png");
   	if(!image[3]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

	image[4] = IMG_Load("number/16.png");
   	if(!image[4]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };    

    image[5] = IMG_Load("number/32.png");
   	if(!image[5]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

    image[6] = IMG_Load("number/64.png");
   	if(!image[6]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

    image[7] = IMG_Load("number/128.png");
   	if(!image[7]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

    image[8] = IMG_Load("number/256.png");
   	if(!image[8]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

    image[9] = IMG_Load("number/512.png");
   	if(!image[9]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

    image[10] = IMG_Load("number/1024.png");
   	if(!image[10]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

    image[11] = IMG_Load("number/2048.png");
   	if(!image[11]) {
       	printf("IMG_Load: %s\n", IMG_GetError());//gestion des erreurs
       	SDL_Quit(); // Arrêt de la SDL
    };

    return image;
}
