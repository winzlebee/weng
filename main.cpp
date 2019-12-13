#include <iostream>
#include <exception>

#include "game.h"

void init(weng::Game *game) {
    // Called when the game is setup and before rendering begins
    weng::Sprite test("Player", "sprite_sheet.png");
    game->addSprite(test);
}

void update(weng::Game *game) {
    // Update is called once per frame

}

int main(int argc, char **argv) {

    // Create a game and start it.
    weng::Game g("Win's Game", &init, &update);

    try {
        g.begin();
    } catch (const weng::InitException &ex) {

        // Error during initialization
        std::cerr << ex.what();
        return 1;
    } catch (const weng::ImageException &imgEx) {

        // Error loading and using an image file
        std::cerr << imgEx.what();
        return 1;
    }

    return 0;

}