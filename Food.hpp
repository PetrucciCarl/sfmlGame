//
// Created by nickobelic1999 on 31/07/2023.
//

#pragma once

#include "Engine.hpp"

#include "SFML/Graphics.hpp"
#include <random>
#include <iostream>

namespace CoreGame
{

    /*
    Food: represents the Food object snake eats.
    It is represented by a sf::RectangleShape
    */

    class Food
    {
    public:
        Food(sf::RenderWindow *, sf::Vector2f loc);
        sf::RectangleShape getFood();
        void drawFood();
        ~Food() { std::cout << "Food\n"; }
    private:
        sf::Color color;
        sf::Vector2f location;
        sf::RectangleShape food;
        sf::RenderWindow *screen;
    };

} // CoreGame
