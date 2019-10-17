#include "simonSays.h"

/*Constructor
*   -Takes care of SDL init
*/

/*
enum color {

    DEFAULT;
    RED_RIGHT;
    BLUE_LEFT;
    YELLOW_UP;
    GREEN_DOWN;
    COLOR_TOTAL;

};
*/
simonSays::simonSays() {

    initGame();

}

//Destructor
simonSays::~simonSays() {

    //Closes SDL Subsystems
    closeSDL( mainWindow, mainSurface );

}

//Main game loop housed here
void simonSays::play() {

    //Win/Lose Flag
    bool winFlag = false;

    int score = 0;

    for ( int i = 1; i <= 4; i++ ) {

        simonList.insert( i );
    }

    simonTurn( simonList );

    //Main game loop
    while ( winFlag ) {

            //Add a random number [1,4] to the list
            simonList.insert( dist( mt );

            printf( "Simon's turn!\n" );
            simonTurn( simonList );

            //SDL_Delay( 2000 );
            printf( "Your turn!\n" );

            winFlag = playerTurn( simonList );

            if ( winFlag ) {

                score++;
            }
    }

    printf( "Game Over!\n" );
    printf( "Your score is: %d\n", score );

    return;
}

/*Closes game
void simonSays::quit() {



}

//Returns a random integer between 1-4
int simonSays::getRandomInt() {

    return ;
}*/

//Replays what is in list
void simonSays::simonTurn( list aList ) {

    for ( int place = 1; place <= aList.getSize(); place++ ) {

            SDL_BlitScaled( colorSurfaces[ aList.getValAt( place ) ], NULL, mainSurface, &boxRect );
            SDL_UpdateWindowSurface( mainWindow );
            SDL_Delay( 2000 );
    }

    //Reset window
    SDL_BlitScaled( colorSurfaces[ DEFAULT ], NULL, mainSurface, &boxRect );
    SDL_UpdateWindowSurface( mainWindow );
    SDL_Delay( 2000 );

    return;
}

bool simonSays::playerTurn( list aList ) {

    bool correct = true;
    int place = 1;

    SDL_Event playerInput;

    do {

        //Handle events on queue
        while ( SDL_PollEvent( &playerInput ) != 0 ) {

            //Player wants to quit; exit game
            if ( playerInput.type == SDL_QUIT ) {

                    correct = false;
            }
            else if ( playerInput.type == SDL_KEYUP ) {

                    switch ( playerInput.key


        }

    } while ( correct );

    return correct;
}

void simonSays::initGame() {

    //Main window and surface initializations
    mainWindow = NULL;
    mainSurface = NULL;
    mainWindow = initSDL( mainSurface, WIDTH, HEIGHT );

    //BoxRect initializations
    boxRect = { WIDTH/2 - BOXSIZE/2, HEIGHT/2 - BOXSIZE/2, BOXSIZE, BOXSIZE };

    //colorSurfaces initalizer
    colorSurfaces[ DEFAULT ] = SDL_CreateRGBSurface( 0, WIDTH, HEIGHT, 32, 0, 0, 0, 0 );
    SDL_FillRect( colorSurfaces[ DEFAULT ], NULL, SDL_MapRGB( mainSurface->format, 255, 255, 255 ) );

    colorSurfaces[ RED_RIGHT ] = loadImage( "images/RED_RIGHT.png", mainSurface );
    colorSurfaces[ BLUE_LEFT ] = loadImage( "images/BLUE_LEFT.png", mainSurface );
    colorSurfaces[ YELLOW_UP ] = loadImage( "images/YELLOW_UP.png", mainSurface );
    colorSurfaces[ GREEN_DOWN ] = loadImage( "images/GREEN_DOWN.png", mainSurface );

    // Make whole screen white and set default surface
    SDL_FillRect( mainSurface, NULL, SDL_MapRGB( mainSurface->format, 255, 255, 255 ) );
    SDL_BlitScaled ( colorSurfaces[ DEFAULT ], NULL, mainSurface, &boxRect );

    //Update window surface
    SDL_UpdateWindowSurface( mainWindow );
    return;
}



