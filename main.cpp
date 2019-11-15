#include <iostream>
#include <exception>

#include "game.h"

int main(int argc, char **argv) {

    // Create a game and start it.
    weng::Game g;

    try {
        g.begin();
    } catch (const weng::InitException &ex) {
        std::cerr << ex.what();
        return 1;
    }

    return 0;

}