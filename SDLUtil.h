//Holds main SDL Utilites

#ifndef SDLUTIL_H
#define SDLUTIL_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_Image.h>

//Initializes SDL
SDL_Window * initSDL( SDL_Surface *& mainSurface, int width, int height);

//Loads an optimized image
SDL_Surface * loadImage( const char * imageLoc, SDL_Surface * mainSurface );

//Closes SDL
void closeSDL ( SDL_Window * mainWindow, SDL_Surface * mainSurface );

#endif
