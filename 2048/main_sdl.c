//
// main_sdl.c
// 2048
// 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include "grille.h"
#include "move.h"
#include "check.h"
#include "appear.h"

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)
#define SCREEEN_BPP (32)
#define MS (300)
int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));

	//initialiser la grille pour fair la calcul
	int** grille = Creer_Grille();
	if (!grille){
		printf("Error en initialisation de la grille:%s\n", SDL_GetError());
		return -1;
	}
	//initialiser SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		printf("Erruer en initialisation de SDL:%s\n", SDL_GetError());
		return -1;
	}
	//creer la fenetre
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("2048",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,SCREEEN_BPP);
	if (window ==NULL){
		printf("Error en creation de la fenetre:%s\n", SDL_GetError());
	}

	//creer un renderer
	Uint32 renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* rend = SDL_CreateRenderer(window ,-1,renderer_flags);
	if(!rend){
		printf("Erreur en creation du renderer:%s\n",SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	//telecharger tout image un memoire
	SDL_Surface* image_2 = IMG_Load("number/2.bmp");
	if (!image_2){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_4 = IMG_Load("number/4.bmp");
	if (!image_4){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_8 = IMG_Load("number/8.bmp");
	if (!image_8){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_16 = IMG_Load("number/16.bmp");
	if (!image_16){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_32 = IMG_Load("number/32.bmp");
	if (!image_32){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_64 = IMG_Load("number/64.bmp");
	if (!image_64){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_128 = IMG_Load("number/128.bmp");
	if (!image_2){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_256 = IMG_Load("number/256.bmp");
	if (!image_256){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_512 = IMG_Load("number/512.bmp");
	if (!image_512){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_1024 = IMG_Load("number/1024.bmp");
	if (!image_1024){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	SDL_Surface* image_2048 = IMG_Load("number/2048.bmp");
	if (!image_2048){
		printf("Error on loading image: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	//les faires en texture
	SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend,image_2);
	SDL_FreeSurface(image_2);
	SDL_Texture* tex4 = SDL_CreateTextureFromSurface(rend,image_4);
	SDL_FreeSurface(image_4);
	SDL_Texture* tex8 = SDL_CreateTextureFromSurface(rend,image_8);
	SDL_FreeSurface(image_8);
	SDL_Texture* tex16 = SDL_CreateTextureFromSurface(rend,image_16);
	SDL_FreeSurface(image_16);
	SDL_Texture* tex32 = SDL_CreateTextureFromSurface(rend,image_32);
	SDL_FreeSurface(image_32);
	SDL_Texture* tex64 = SDL_CreateTextureFromSurface(rend,image_64);
	SDL_FreeSurface(image_64);
	SDL_Texture* tex128 = SDL_CreateTextureFromSurface(rend,image_128);
	SDL_FreeSurface(image_128);
	SDL_Texture* tex256 = SDL_CreateTextureFromSurface(rend,image_256);
	SDL_FreeSurface(image_256);
	SDL_Texture* tex512 = SDL_CreateTextureFromSurface(rend,image_512);
	SDL_FreeSurface(image_512);
	SDL_Texture* tex1024= SDL_CreateTextureFromSurface(rend,image_1024);
	SDL_FreeSurface(image_1024);
	SDL_Texture* tex2048 = SDL_CreateTextureFromSurface(rend,image_2048);
	SDL_FreeSurface(image_2048);

	SDL_Rect destTitle;
	SDL_QueryTexture(tex2048,NULL,NULL,&destTitle.w,&destTitle.h);
	destTitle.w = WINDOW_WIDTH;
	destTitle.h = WINDOW_HEIGHT;
	destTitle.x = 0;
	destTitle.y = WINDOW_HEIGHT;

	//le mettre in 1 quand on veut le fermer
	int close_command = 0;
			long y_pos = WINDOW_HEIGHT;
	//pour raccord l'entree a clavier
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;

	//loop d'animation
	while(!close_command){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					close_command = 1;break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.scancode){
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							up = 1;break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							left = 1;break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							down = 1;break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							right = 1;break;
					}break;
				case SDL_KEYUP:
					switch(event.key.keysym.scancode)
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							up = 0;break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							left = 0;break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							down = 0;break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							right = 0;break;					
			}break;
		}

		//overture de jeu
		while(y_pos > -500){
			SDL_RenderClear(rend);
			destTitle.y = (int) y_pos;

			//copy texture de 2048 en surface de la destination (destTitle)
			SDL_RenderCopy(rend,tex2048,NULL,&destTitle);
			SDL_RenderPresent(rend);

			y_pos -=(long) MS/60;
			SDL_Delay(1000/60);
		}
		/*
		le jeu ici

		*/






	}
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}