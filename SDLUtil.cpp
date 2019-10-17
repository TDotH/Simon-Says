#include "SDLUtil.h"


//Initializes SDL
SDL_Window * initSDL( SDL_Surface *& mainSurface, int width, int height ) {

    const char * title = "Simon Says v1.0";

    SDL_Window * mainWindow = NULL;

    //Initialize SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {

        printf( "Unable to initalize SDL: %s", SDL_GetError() );
    } else {

        //Create Window
        mainWindow = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

        //Create window surface
        mainSurface = SDL_GetWindowSurface( mainWindow );

        //Load support for PNG image format
        int imgFlags = IMG_INIT_PNG;
        if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {

                printf( "SDL_image could not initialize! Error: %s\n", IMG_GetError() );
        }
    }

    return mainWindow;
}

//Loads an optimized image
SDL_Surface * loadImage( const char * imageLoc, SDL_Surface * mainSurface ) {

    //Final optimized image
    SDL_Surface * optImage = NULL;

    SDL_Surface * loadedImage = IMG_Load( imageLoc );
    if ( !loadedImage ) {

        printf( "Unable to load image %s! Error: %s\n", imageLoc, IMG_GetError() );
    } else {

        //Convert image to screen format
        optImage = SDL_ConvertSurface( loadedImage, mainSurface->format, 0);

        if ( !optImage ) {

                printf( "Unable to optimize image %s! Error: %s\n", imageLoc, IMG_GetError() );
        }

        //Free previous image
        SDL_FreeSurface( loadedImage );
    }

    return optImage;
}

//Closes SDL
void closeSDL ( SDL_Window * mainWindow, SDL_Surface * mainSurface ) {

    //Free current surface
    SDL_FreeSurface( mainSurface );
    mainSurface = NULL;

    //Free window
    SDL_DestroyWindow( mainWindow );
    mainWindow = NULL;

    SDL_Quit();
}
