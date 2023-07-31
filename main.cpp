//
// Created by nickobelic1999 on 12/07/2023.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window( sf::VideoMode( 800, 800 ), "Snake", sf::Style::Close );
    game::MainMenu menu;
    menu.start(&window);
    return 0;
}