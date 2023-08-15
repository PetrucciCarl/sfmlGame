//
// Created by nickobelic1999 on 12/07/2023.
//

#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"


int main()
{
    std::string title = "Snake";
    sf::RenderWindow window(sf::VideoMode(800, 600), title, sf::Style::Close);
    UI::MainMenu menu;
    menu.start(&window);
    return 0;
}