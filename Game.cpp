//
// Created by nickobelic1999 on 2/08/2023.
//

#include "Game.hpp"

CoreGame::GameController::GameController(sf::RenderWindow *w, const std::string &filename)
    : snake(w), filename(filename) {
    scale           = 5;
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
    Food *food = new Food(screen,snake.getNextFoodLocation());
    while(loopInvarient)
    {
        setupScene();
        food->drawFood();
        sf::Event event{};
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
            // Before we die, we need too:
            // 0 - Read in scores file
            readScores();

            scoresList.emplace_back(name, score);
            // 1 - Ask for username.
            // 2 - Check username in json file.
            // 3 - Check score, if score is greater than current score update score.
            // 4 - Order file from highest to lowest.
            sortScores();

            // 5 - Write new file backout.
            writeScores();

            //game Over
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
    auto highscores = std::ifstream(filename, std::ios::in);

    // Check for file and verify it was created.
    if(highscores)
    {
        // Parse the file
        std::cout << "Parsing scores file...\n";

        std::string line;

        while(std::getline(highscores, line))
        {
            auto scoreName = line.substr(0, line.find(','));
            auto scoreScore = line.substr(line.find(',')+1);
            scoresList.emplace_back(scoreName, std::stoi(scoreScore));
        }
    }
    else
    {
        std::cerr << "On death, unable to create HighScores.txt!" << std::endl;
    }

}

void CoreGame::GameController::sortScores()
{

    std::sort(scoresList.begin(), scoresList.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
                    {
                        return a.second < b.second;
                    });


}

void CoreGame::GameController::writeScores()
{
    // Dump scores list to output file stream
    std::string scores;

    for(const auto& i : scoresList)
        scores += i.first + "," + std::to_string(i.second) + "\n";

    auto highscores = std::ofstream(filename, std::ios::trunc);
    highscores << scores;
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
