#ifndef __disp_pack1__
#define __disp_pack1__

SDL_Surface* load_image(char* filename);
void apply_image(int x ,int y,SDL_Surface* source, SDL_Surface* destination);
bool __init_sdl__();

#endif


#define SCREEN_WIDTH 640
#define SCREEN_WIDTH 480
#define SCREEN_BPP 32