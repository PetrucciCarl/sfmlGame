//
// Created by nickobelic1999 on 2/08/2023.
//

#include "Game.hpp"

CoreGame::GameController::GameController(sf::RenderWindow *w, const std::string &filename)
    : snake(w), filename(filename) {
    screen          = w;
    score           = 0;
    loopInvarient   = true;
}

void CoreGame::GameController::start()
{
    loadResources();
    gameLoop();
}

void CoreGame::GameController::gameLoop()
{

    sf::Vector2<int> direction(-1,0);
    scale = 5;
    Food *food = new Food(screen,snake.getNextFoodLocation());
    while(loopInvarient)
    {
        setupScene();
        food->drawFood();
        sf::Event event;
        while(screen->pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Up)
                {
                    direction.y = -1;
                    direction.x = 0;
                } else if (event.key.code == sf::Keyboard::Down) {
                    direction.y = 1;
                    direction.x = 0;
                }
                else if (event.key.code == sf::Keyboard::Left) {
                    direction.x = -1;
                    direction.y = 0;
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    direction.x = 1;
                    direction.y = 0;
                }
            }
            if (event.type == sf::Event::Closed) {
                exit(0);
            }
        } //event loop
        snake.moveSnake(direction);
        if (snake.died())
        {
            //game Over

            // This is where score needs to be saved
            // 0 - Read in scores file
            readScores();

            // 1 - Ask for username.
            // 2 - Check username in json file.

            // 3 - Check score, if score is greater than current score update score.
            // 4 - Order file from highest to lowest.
            sortScores();

            // 5 - Write new file backout.
            submitScore();

            gameOver();

        }
        if (snake.ateFood(food))
        {
            // Updates score.
            score++;
            // Increases speed once food has been eaten.
            snake.updateSpeed(0.1);
            // Removes food from screen and creates new food.
            delete food;
            food = new Food(screen, snake.getNextFoodLocation());
        }
        screen->display();
        screen->setFramerateLimit(60);
    }
}

void CoreGame::GameController::setupScene()
{
    screen->clear();
    snake.drawSnake();
}

void CoreGame::GameController::readScores()
{
    //File input stream
    std::ifstream highscores(filename);

    // Check for file and verify it was created.
    if(!highscores)
    {
        // HighScores.txt doesn't exists
        std::cerr << "No such files exists, created scores file!\n";

        // Initialises json file
        scoresList = {{name}, {score}};
    }
    else
    {
        // Parse the file
        std::cout << "Parsing scores file...\n";
        scoresList = json::parse(std::ifstream(filename));
        // Append new scores to parsed json file
        scoresList += {{name}, {score}};
        /* Dump to the console, ensure that formatting is correct
           This should only be used for debugging
           */
        std::cout << std::setw(2) << scoresList.dump() << "\n\n";
    }

}

void CoreGame::GameController::sortScores()
{

    std::sort(scoresList.begin(), scoresList.end(),
              [this](const json& a, const json& b)
                    {
                        return a[score] < b[score];
                    });

}

void CoreGame::GameController::submitScore()
{
    //Create highscores file output stream
    std::ofstream highscores(filename, std::ios::out | std::ios::trunc);
    // Dump scores list to output file stream
    highscores << scoresList.dump();
    highscores.close();
}

void CoreGame::GameController::gameOver()
{

    loopInvarient = false;
}

bool CoreGame::checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b)
{
    return a.getGlobalBounds().intersects( b.getGlobalBounds() );

}

sf::RectangleShape CoreGame::getRectangleAt(sf::Vector2f location, sf::Color color)
{
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box.setPosition(location);
    box.setFillColor(color);
    return box;

}

void CoreGame::GameController::loadResources()
{
    //TODO
}

sf::Font* CoreGame::GameController::getFont(Fonts font)
{
    return &fontList[font];
}
