#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>
#include<stdbool.h>

#include "display_pack1.h"
SDL_Surface* screen = NULL;


SDL_Surface* load_image(char* filename){
	//e,g of filename: "number/2.bmp" while inside "number" folder
	//temporary image
	SDL_Surface* temp = NULL;
	SDL_Surface* formatted_image = NULL;
	temp = SDL_LoadBMP(filename);
	if(temp!=NULL){
		//reformat image to fit SDL screen format
		formatted_image = SDL_DisplayFormat(temp);
		SDL_FreeSurface(temp);
	}
	return formatted_image;
}

void apply_image(int x ,int y,SDL_Surface* source, SDL_Surface* destination){
	//paste souce to position x,y to distination(screen)
	//temporary rect to hold offset(position)
	SDL_Rect offset;

	offset.x =x;
	offset.y = y;

	//paste image of source on top of destination with offset poistion
	SDL_BlitSurface(source,NULL,destination,&offset);
	//update screen
	SDL_Flip(screen);
}

bool __init_sdl__(){
	if(SDL_Init(INIT_EVERYTHING)==-1){
		return false;
	}//initialise all sdl subsystems and raise error if unable
	//set up screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEP_BPP,SDL_SWSURFACE);
	//chech that screen is setup
	if(screen ==NULL){
		printf("Unable to setup screen. SDL_Error: %s\n",SDL_GetError());
	}
	SDL_WM_SetCaption("2048",NULL);
	return true;
}


