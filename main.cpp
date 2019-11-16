#include <iostream>
#include <exception>

#include "game.h"

int main(int argc, char **argv) {

    // Create a game and start it.
    weng::Game g;

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