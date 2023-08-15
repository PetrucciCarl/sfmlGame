//
// Created by nickobelic1999 on 31/07/2023.
//

#include "MainMenu.hpp"

#include "Game.hpp"
#include "GameMenu.hpp"

namespace UI
{
    void MainMenu::start( sf::RenderWindow * w ) {
        sf::Font defaultFont;
        defaultFont.loadFromFile("sansation.ttf");
        gmenu::Style style( defaultFont, defaultFont);
        gmenu::Menu menu( *w, "ButtsMcGee", {}, style );
        action[0] = new StartGameAction( w );
        action[3] = new ExitAction( w );
        std::vector<gmenu::MenuItem> items;
        for ( int i = 0; i < 4; ++i ) {
            items.push_back(gmenu::MenuItem{std::shared_ptr<gmenu::Action>(action[i]), MenuText[i]});
        }
        items[3].action.reset(action[3]);
        menu.setMenuItems( items );
        menu.setTitle( "Sfml-Snake" );
        menu.createMenu();
    }


    StartGameAction::StartGameAction( sf::RenderWindow *w ) {
        window = w;
    }

    bool StartGameAction::start() {
        CoreGame::GameController gameController( window );
        gameController.start();
        return true;
    }



    HighScoreAction::HighScoreAction( sf::RenderWindow *w ) {
        window = w;
    }

    bool HighScoreAction::start() {
        return false;
    }

    OptionsAction::OptionsAction( sf::RenderWindow *w ) {
        window = w;
    }

    bool OptionsAction::start() {
        return false;
    }

    ExitAction::ExitAction( sf::RenderWindow *w ) {
        window = w;
    }

    bool ExitAction::start() {
        if ( getConfirmation() )
            return false; // means exit
        return true;
    }

    bool ExitAction::getConfirmation() {
        bool confirm = false;
        gmenu::MenuItem items[2]; //Creating a list of Menu Items for the Dialog
        items[0].title = "Yes";
//        items[0].action = new ExitAction::ConfirmationMenuAction( &confirm );
        items[1].title = "No";
//        items[1].action = new ExitAction::DeclineMenuAction( &confirm );
//        gmenu::Menu dialog( window, "Are you sure?", items, 2 ); //Creating the confirmation dialog
//        dialog.createMenu();
        return confirm;
    }
}