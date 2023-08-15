//
// Created by nickobelic1999 on 31/07/2023.
//

#pragma once

#include "SFML/Graphics.hpp"


namespace CoreGame
{
    /*
    Contains functions that will be used to perform certain
    actions that will be needed that will be needed by game

    */

    bool checkCollision(const sf::RectangleShape&, const sf::RectangleShape& );

    /* Returns a rectangle at the specified coordinates */
    sf::RectangleShape getRectangleAt(sf::Vector2f location, sf::Color);

}
