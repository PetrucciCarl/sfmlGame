//
// Created by nickobelic1999 on 2/08/2023.
//

#pragma once

#include "Snake.hpp"
#include "Food.hpp"

namespace CoreGame
{
    /*
    GameController is the central interface of the game.
    This class will monitor the working of game:
    *	Movement of snake
    *	Checking collisions
    *	When to play sound etc
    */


    const std::string MenuStrings[5] = {
            "Game Over!",
            "Do you wish to continue?",
            "Yes",
            "No",
            "Exit"
    }; //menu strings

    enum MenuText {
        GameOver,
        Continue,
        Yes,
        No,
        Exit,
    }; //menuText

    enum Fonts
    {};

    class GameController
    {
    public:

        void start();

        sf::Font* getFont(Fonts font);


        GameController(sf::RenderWindow* w);

    private:

        //Main game loop
        void gameLoop();

        //Setup scene
        void setupScene();

        // Game over
        void gameOver();

        //load resources
        void loadResources();

        Snake snake;
        sf::RenderWindow* screen;
        sf::Font fontList[3];

        float scale;
        int score;

    };

}


