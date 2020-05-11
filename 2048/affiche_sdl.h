//
// affiche_sdl.h
// 2048
// 

#ifndef affiche_sdl_h
#define affiche_sdl_h

#include <SDL.h>
#include <SDL_image.h>

//Affiche la grille de jeu
void Affiche_Grille_SDL(int** grille, SDL_Surface* ecran, SDL_Surface** image);

//Charger toutes les images
SDL_Surface** Load_Image(void);

#endif /* affiche_sdl_h */