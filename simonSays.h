// Class that holds main game logic
#ifndef SIMONSAYS_H
#define SIMONSAYS_H

#include "linkedList.h"
#include "SDLUtil.h"

#include <random>
#include <chrono>

enum color {

    DEFAULT,
    RED_RIGHT,
    BLUE_LEFT,
    YELLOW_UP,
    GREEN_DOWN,
    COLOR_TOTAL
};

class simonSays {

    public:

        simonSays();
        ~simonSays();

        void play();
        //void quit();

    private:

        const int WIDTH  = 800;
        const int HEIGHT = 600;
        const int BOXSIZE = 400;

        //Random number generation
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 4);

        list simonList;
        //color simonColors;

        SDL_Window  * mainWindow;
        SDL_Surface * mainSurface;
        SDL_Surface * colorSurfaces[ COLOR_TOTAL ];

        SDL_Rect boxRect;

        //int getRandomInt();

        void simonTurn ( list aList );
        bool playerTurn( list aList );

        void initGame();
};

#endif
